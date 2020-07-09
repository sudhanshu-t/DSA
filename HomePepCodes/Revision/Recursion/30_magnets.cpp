#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool db = true;

vector<string> blocks = {"+-", "-+", "xx"};

bool canPlaceH(int bno, string block, vector<vector<char>>& rules){
    int i = bno / rules[0].size();
    int j = bno % rules[0].size();


    if(rules[i][j] != 'L'){
        return false;
    }

    if(j+1 >= rules[0].size()){
        return false;
    }

    if(block == "xx"){
        return true;
    }

    if(j-1 >= 0 && rules[i][j-1] == block[0]){
        return false;
    }

    if(i-1 >= 0 && rules[i-1][j] == block[0]){
        return false;
    }

    if(i+1 < rules.size() && rules[i+1][j] == block[0]){
        return false;
    }

    if(j+2 < rules[0].size() && rules[i][j+2] == block[1]){
        return false;
    }

    if(i-1 >= 0 && rules[i-1][j+1] == block[1]){
        return false;
    }

    if(i+1 < rules.size() && rules[i+1][j+1] == block[1]){
        return false;
    }

    return true;
}

void placeH(int bno, string block, vector<vector<char>>& rules){
    int i = bno / rules[0].size();
    int j = bno % rules[0].size();

    rules[i][j] = block[0];
    rules[i][j+1] = block[1];
}

void unplaceH(int bno, string block, vector<vector<char>>& rules){
    int i = bno / rules[0].size();
    int j = bno % rules[0].size();

    rules[i][j] = 'L';
    rules[i][j+1] = 'R';
}

bool canPlaceV(int bno, string block, vector<vector<char>>& rules){
    int i = bno / rules[0].size();
    int j = bno % rules[0].size();

    if(rules[i][j] != 'T'){
        return false;
    }

    if(i+1 >= rules.size()){
        return false;
    }

    if(block == "xx"){
        return true;
    }

    if(i-1 >= 0 && rules[i-1][j] == block[0]){
        return false;
    }

    if(j-1 >= 0 && rules[i][j-1] == block[0]){
        return false;
    }

    if(j+1 < rules[0].size() && rules[i][j+1] == block[0]){
        return false;
    }

    if(i+2 < rules.size() && rules[i+2][j] == block[1]){
        return false;
    }

    if(j-1 >= 0 && rules[i+1][j-1] == block[1]){
        return false;
    }

    if(j+1 < rules[0].size() && rules[i+1][j+1] == block[1]){
        return false;
    }

    return true;
}

void placeV(int bno, string block, vector<vector<char>>& rules){
    int i = bno / rules[0].size();
    int j = bno % rules[0].size();

    rules[i][j] = block[0];
    rules[i+1][j] = block[1];
}

void unplaceV(int bno, string block, vector<vector<char>>& rules){
    int i = bno / rules[0].size();
    int j = bno % rules[0].size();

    rules[i][j] = 'T';
    rules[i+1][j] = 'B';
}

void magnets(int bno, vector<vector<char>>& rules, vector<int>& top, vector<int>& bottom, vector<int>& left, vector<int>& right){
    if(bno == rules.size() * rules[0].size()){
        int pcount = 0, ncount = 0;
        for(int j = 0; j < rules[0].size(); j++){
            for(int i = 0; i < rules.size(); i++){
                if(rules[i][j] == '+'){
                    pcount++;
                }

                if(rules[i][j] == '-'){
                    ncount++;
                }
            }

            if((top[j] != -1 && pcount != top[j]) || (bottom[j] != -1 && ncount != bottom[j])){
                return;
            }
        }

        pcount = 0;
        ncount = 0;
        for(int i = 0; i < rules.size(); i++){
            for(int j = 0; j < rules[0].size(); j++){
                if(rules[i][j] == '+'){
                    pcount++;
                }

                if(rules[i][j] == '-'){
                    ncount++;
                }
            }

            if((left[i] != -1 && pcount != left[i]) || (right[i] != -1 && ncount != right[i])){
                return;
            }
        }

        for(int i = 0; i < rules.size(); i++){
            for(int j = 0; j < rules[0].size(); j++){
                cout << rules[i][j] << " ";
            }

            cout << endl;
        }

        return;
    }

    for(int i = 0; i < rules.size(); i++){
        for(int j = 0; j < rules[0].size(); j++){
            cout << rules[i][j] << " ";
        }

        cout << endl;
    }

    if(db)
        cout << bno << "npre" << endl;

    for(int i = 0; i < blocks.size(); i++){
        if(canPlaceH(bno, blocks[i], rules)){
            placeH(bno, blocks[i], rules);

            if(db)
                cout << bno << " " << blocks[i] << "epre h" << endl;

            magnets(bno+1, rules, top, bottom, left, right);
            
            if(db)
                cout << bno << " " << blocks[i] << "epost h" << endl;

            unplaceH(bno, blocks[i], rules);
        } else if(canPlaceV(bno, blocks[i], rules)){
            placeV(bno, blocks[i], rules);

            if(db)
                cout << bno << " " << blocks[i] << "epre v" << endl;

            magnets(bno+1, rules, top, bottom, left, right);

            if(db)
                cout << bno << " " << blocks[i] << "epost v" << endl;

            unplaceV(bno, blocks[i], rules);
        } else {
            magnets(bno+1, rules, top, bottom, left, right);
        }
    }

    if(db)
        cout << bno << "npost" << endl;
}

int main(int argc, char** argv){
    vector<int> top = { 1, -1, -1, 2, 1, -1 };
    vector<int> bottom = { 2, -1, -1, 2, -1, 3 };
    vector<int> left = { 2, 3, -1, -1, -1 };
    vector<int> right = { -1, -1, -1, 1, -1 };
    vector<vector<char>> rules = { 
        { 'L', 'R', 'L', 'R', 'T', 'T' },
        { 'L', 'R', 'L', 'R', 'B', 'B' },
        { 'T', 'T', 'T', 'T', 'L', 'R' },
        { 'B', 'B', 'B', 'B', 'T', 'T' },
        { 'L', 'R', 'L', 'R', 'B', 'B' }
    };

    magnets(0, rules, top, bottom, left, right);
}