#include <iostream>
#include <string>
#include <vector>

#define vc vector<char>
#define vvc vector<vc>

using namespace std;

int db = false;

bool canPlaceH(vector<vector<char>>& board, int r, int c, string word){
    if(c + word.size() > board.size()){
        // cout << '1' << endl;
        return false;
    }

    else if(c-1 >= 0 && board[r][c-1] != '+'){
        // cout << '2' << endl;
        return false;
    }

    else if(c+word.size() < board.size() && board[r][c+word.size()] != '+'){
        // cout << '3' << endl;
        return false;
    }
    
    else{
        // cout << '4' << endl;
        for(int j = c; j < c+word.size(); j++){
            if(board[r][j] != '-' && board[r][j] != word[j-c]){
                return false;
            }
            // cout << '6' << endl;
        }
        // cout << '5' << endl;
    }

    return true;
}

void placeH(vector<vector<char>>& board, int r, int c, string word, bool reset[]){
    for(int j = c; j < c+word.size(); j++){
        if(board[r][j] == '-'){
            reset[j-c] = true;
        }

        board[r][j] = word[j-c];
    }
}

void unPlaceH(vector<vector<char>>& board, int r, int c, string word, bool reset[]){
    // cout << '7' << endl;
    for(int j = c; j < c+word.size(); j++){
        if(reset[j-c] == true){
            board[r][j] = '-';
        }
    }
}

bool canPlaceV(vector<vector<char>>& board, int r, int c, string word){
    if(r + word.size() > board.size()){
        return false;
    }

    else if(r-1 >= 0 && board[r-1][c] != '+'){
        return false;
    }

    else if(r + word.size() < board.size() && board[r+word.size()][c] != '+'){
        return false;
    }

    else {
        for(int i = r; i < r + word.size(); i++){
            if(board[i][c] != '-' && board[i][c] != word[i-r]){
                return false;
            }
        }
    }

    return true;
}

void placeV(vector<vector<char>>& board, int r, int c, string word, bool reset[]){
    for(int i = r; i < r+word.size(); i++){
        if(board[i][c] == '-'){
            reset[i-r] = true;
        }

        board[i][c] = word[i-r];
    }
}

void unPlaceV(vector<vector<char>>& board, int r, int c, string word, bool reset[]){
    for(int i = r; i < r+word.size(); i++){
        if(reset[i-r] == true){
            board[i][c] = '-';
        }
    }
}

void crossword_bc(vvc& board, vector<string>& words, int bno, int wpsf, bool itwp[]){
    if(bno == board.size() * board.size()){
        if(wpsf == words.size()){
            for(int i = 0; i < board.size(); i++){
                for(int j = 0; j < board[0].size(); j++){
                    cout << board[i][j] << " ";
                }

                cout << endl;
            }
        }

        return;
    }

    if(db){
        cout << bno << 'a' << endl;
    }

    int r = bno / board.size();
    int c = bno % board.size();

    for(int i = 0; i < words.size(); i++){
        if(itwp[i] == false){
            // cout << "TD" << endl;

            if(board[r][c] == '-' || board[r][c] == words[i][0]){

            // Horizontal
                if(canPlaceH(board, r, c, words[i]) == true){
                    itwp[i] = true;

                    bool reset[words[i].size()];
                    for(int x = 0; x < words[i].size(); x++){
                        reset[x] = false;
                    }

                    placeH(board, r, c, words[i], reset);

                    if(db){
                        cout << r << c << " " << bno << 'A' << endl;
                    }
                    crossword_bc(board, words, bno+1, wpsf+1, itwp);
                    if(db){
                        cout << r << c << " " << bno << 'B' << endl;
                    }
                    unPlaceH(board, r, c, words[i], reset);

                    itwp[i] = false;
                }

            // Vertical
                if(canPlaceV(board, r, c, words[i]) == true){
                    itwp[i] = true;
                    
                    bool reset[words[i].size()];
                    for(int x = 0; x < words[i].size(); x++){
                        reset[x] = false;
                    }

                    placeV(board, r, c, words[i], reset);

                    if(db){
                        cout << r << c << " " << bno << 'A' << endl;
                    }
                    crossword_bc(board, words, bno+1, wpsf+1, itwp);
                    if(db){
                        cout << r << c << " " << bno << 'B' << endl;
                    }
                    unPlaceV(board, r, c, words[i], reset);

                    itwp[i] = false;
                }
            }

            else{
                crossword_bc(board, words, bno+1, wpsf, itwp);
            }
        }   
    }
}

int main(int argc, char** argv){
    vector<vector<char>> board = {
        {'+','+','+','+','+','+','-','+','+','+'},
        {'+','+','-','-','-','-','-','-','+','+'},
        {'+','+','+','+','+','+','-','+','+','+'},
        {'+','+','+','+','+','+','-','+','+','+'},
        {'+','+','+','-','-','-','-','-','-','+'},
        {'+','+','+','+','+','+','-','+','-','+'},
        {'+','+','+','+','+','+','-','+','-','+'},
        {'+','+','+','+','+','+','+','+','-','+'},
        {'+','+','+','+','+','+','+','+','-','+'},
        {'+','+','+','+','+','+','+','+','-','+'}
    };

    vector<string> words = {"ICELAND","MEXICO", "PANAMA", "ALMATY"};

    bool itwp[words.size()] = {false, false, false, false};

    crossword_bc(board, words, 0, 0, itwp);

    for(int i = 0; i < 4; i++){
        cout << itwp[i] << " ";
    }

    cout << endl;
}