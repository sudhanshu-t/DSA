#include <iostream>
#include <vector>
#include <string>

using namespace std;

int db = true;

bool canPlaceH(vector<vector<char>>& board, int r, int c, string word){
    if(c + word.size() > board.size()){
        return false;
    }

    else if(c-1 >= 0 && board[r][c-1] != '+'){
        return false;
    }

    else if(c+word.size() < board.size() && board[r][c+word.size()] != '+'){
        return false;
    }
    
    else{
        for(int j = c; j < c+word.size(); j++){
            if(board[r][j] != '-' && board[r][j] != word[j-c]){
                return false;
            }
        }
    }

    return true;
}

void placeH(vector<vector<char>>& board, int r, int c, string word, bool reset[]){
    for(int j = c; j < c+word.size(); j++){
        if(board[r][j] == '-'){
            reset[j-c] = true;
        }
        else{
            reset[j-c] = false;
        }

        board[r][j] = word[j-c];
    }
}

void unPlaceH(vector<vector<char>>& board, int r, int c, string word, bool reset[]){
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
        else{
            reset[i-r] = false;
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

void crossword(vector<vector<char>>& board, int bno, int cw, vector<string>& words, bool itwp[]){
    if(bno == board.size() * board.size()){
        if(cw == words.size()){
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
        if(board[r][c] == '+' || board[r][c] != words[i][0]){
            crossword(board, bno+1, cw, words, itwp);
        }

        else {
            if(itwp[i] == false){
                // Horizontal
                if(canPlaceH(board, r, c, words[i]) == true){
                    bool reset[words[i].size()];

                    placeH(board, r, c, words[i], reset);
                    itwp[i] = true;

                    if(db){
                        cout << r << c << bno << 'a' << endl;
                    }
                    crossword(board, bno+1, cw+1, words, itwp);
                    if(db){
                        cout << r << c << bno << 'a' << endl;
                    }
                    unPlaceH(board, r, c, words[i], reset);
                    itwp[i] = false;
                }

                // Vertical
                if(canPlaceV(board, r, c, words[i]) == true){
                    bool reset[words[i].size()];

                    placeV(board, r, c, words[i], reset);
                    itwp[i] = true;

                    if(db){
                        cout << r << c << bno << 'a' << endl;
                    }
                    crossword(board, bno+1, cw+1, words, itwp);
                    if(db){
                        cout << r << c << bno << 'a' << endl;
                    }
                    unPlaceV(board, r, c, words[i], reset);
                    itwp[i] = false;
                }
            }
        }
    }

    if(db){
        cout << bno << 'b' << endl;
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

    bool itwp[words.size()];
    crossword(board, 0, 0, words, itwp);
}