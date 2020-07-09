#include <iostream>
#include <vector>
#include <string>

using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};

void subseq(string s, string asf){
    if(s.size() == 0){
        cout << asf << endl;
        return;
    }
    
    char c = s[0];

    s = s.substr(1);
    subseq(s, asf + c);
    subseq(s, asf);
}

void kpc(string s, string asf){
    if(s.size() == 0){
        cout << asf << endl;
        return;
    }
    
    char c = s[0];

    s = s.substr(1);

    for(int i = 0; i < codes[c - '0'].size(); i++){
        kpc(s, asf + codes[c - '0'][i]);
    }
}

void stair(int n, string asf){
    if(n == 0){
        cout << asf << endl;
        return;
    }
    if(n < 0){
        return;
    }

    stair(n-1, asf + "1");
    stair(n-2, asf + "2");
    stair(n-3, asf + "3");
}

void print_maze(int sr, int sc, int dr, int dc, string asf){
    if(sr == dr && sc == dc){
        cout << asf << endl;
        return;
    }

    if(sr > dr || sc > dc){
        return;
    }

    print_maze(sr + 1, sc, dr, dc, asf + "V");
    print_maze(sr, sc + 1, dr, dc, asf + "H");
}

void print_maze_multi_move_proactive(int sr, int sc, int dr, int dc, string asf){
    if(sr == dr && sc == dc){
        cout << asf << endl;
        return;
    }
    
    for(int i = 1; sr + i <= dr; i++){
        print_maze_multi_move_proactive(sr + i, sc, dr, dc, asf + "V" + to_string(i));
    }

    for(int i = 1; sc + i < dc; i++){
        print_maze_multi_move_proactive(sr, sc + i, dr, dc, asf + "H" + to_string(i));
    }

    for(int i = 1; sr + i <= dr; i++){
        print_maze_multi_move_proactive(sr + i, sc + i, dr, dc, asf + "D" + to_string(i));
    }
}

vector<vector<int>>* tarsum(int arr[], int idx, int n, int sum){
    if(idx == n && sum == 0){
        vector<vector<int>>* bres = new vector<vector<int>>;
        vector<int> kv;
        bres->push_back(kv);

        return bres;
    }

    if(idx == n && sum < 0){
        vector<vector<int>>* bres = new vector<vector<int>>;
        return bres;
    }
    
    vector<vector<int>>* mres = new vector<vector<int>>();
    
    for(int i = 1; i < n; i++){
        vector<vector<int>>* rres = tarsum(arr, idx + i, n, sum - arr[i-1]);
        
        for(int j = 0; j < rres->size(); j++){
            rres->at(i).push_back(arr[i - 1]);

            mres->push_back(rres->at(i));
        }
    }

    return mres;
}

void tarsum_pre(int arr[], int n, int sum, int idx, string asf){
    if(idx == n){
        if(sum == 0){
            cout << asf << endl;
        }
        return;
    }
    
    tarsum_pre(arr, n, sum - arr[idx], idx + 1, asf + " " + to_string(arr[idx]));
    tarsum_pre(arr, n, sum, idx + 1, asf);
}

int main(int argc, char** argv){
    subseq("abc", "");
    kpc("682", "");
    stair(4, "");
    print_maze(0, 0, 2, 3, "");
    print_maze_multi_move_proactive(0, 0, 2, 2, "");

    int arr[] = {20, 30, 40, 50, 60, 10};
    vector<vector<int>>* v = tarsum(arr, 0, 6, 70);

    for(int i = 0; i < v->size(); i++){
        for(int j = 0; j < (*v)[i].size(); j++){
            cout << (*v)[i][j] << " ";
        }

        cout << endl;
    }

    // tarsum_pre(arr, 6, 70, 0, "");

    return 0;
}