#include <iostream>
#include <string>
#include <vector>

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

        board[i][c] = word[i-r];
    }
}

void unplaceV(vector<vector<char>>& board, int r, int c, string word, bool reset[]){
    for(int i = r; i < r+word.size(); i++){
        if(reset[i-r] == true){
            board[i][c] = '-';
        }
    }
}

void crossword(vector<vector<char>>& board, vector<string>& words, int cw){
    if(cw == words.size()){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                cout << board[i][j] << " ";
            }

            cout << endl;
        }

        return;
    }
    if(db)
    cout << cw << 'a' << endl;

    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            // Horizontal
            if(canPlaceH(board, i, j, words[cw]) == true){
                bool reset[words[cw].size()];
                for(int x = 0; x < words[cw].size(); x++){
                    reset[x] = false;
                }

                placeH(board, i, j, words[cw], reset);

                if(db)
                    cout << i << j << " " << cw << 'a' << endl;
                crossword(board, words, cw+1);
                if(db)
                    cout << i << j << " " << cw << 'b' << endl;
                unPlaceH(board, i, j, words[cw], reset);
            }

            // Vertical
            if(canPlaceV(board, i, j, words[cw]) == true){
                bool reset[words[cw].size()];
                for(int x = 0; x < words[cw].size(); x++){
                    reset[x] = false;
                }

                placeV(board, i, j, words[cw], reset);

                if(db)
                    cout << i << j << " " << cw << 'a' << endl;
                crossword(board, words, cw+1);
                if(db)
                    cout << i << j << " " << cw << 'b' << endl;

                unplaceV(board, i, j, words[cw], reset);
            }
        }
    }

    cout << cw << 'b' << endl;
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

    crossword(board, words, 0);
}