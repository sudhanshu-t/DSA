#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canPlaceH(vector<string>& board, int r, int c, string word){
    if(c + word.size() > board.size()){
        return false;
    }

    else if(c > 0 && board[r][c-1] != '+'){
        return false;
    }

    else if(c + word.size() < board.size() && 
            board[r][c+word.size()] != '+'){
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

bool canPlaceV(vector<string>& board, int r, int c, string word){
    if(r + word.size() > board.size()){
        return false;
    }

    else if(r > 0 && board[r-1][c] != '+'){
        return false;
    }

    else if(r + word.size() < board.size() && 
            board[r+word.size()][c] != '+'){
        return false;
    }

    else{
        for(int i = r; i < r + word.size(); i++){
            if(board[i][c] != '-' && board[i][c] != word[i-r]){
                return false;
            }
        }
    }

    return true;
}

void placeH(vector<string>& board, int r, int c, string word, bool reset[]){
    for(int j = c; j < c+word.size(); j++){
        if(board[r][j] == '-'){
            reset[j-c] = true;
        }
        board[r][j] = word[j-c];
    }
}

void placeV(vector<string>& board, int r, int c, string word, bool reset[]){
    for(int i = 0; i < r+word.size(); i++){
        if(board[i][c] == '-'){
            reset[i-r] = true;
        }
        board[i][c] = word[i-r];
    }
}

void unplaceH(vector<string>& board, int r, int c, string word, bool reset[]){
    for(int j = 0; j < c+word.size(); j++){
        if(reset[j-c] == true){
            board[r][j] = '-';
        }
    }
}

void unplaceV(vector<string>& board, int r, int c, string word, bool reset[]){
    for(int i = r; i < r+word.size(); i++){
        if(reset[i - r] == true){
            board[i][c] = '-';
        }
    }
}

void crossword(vector<string>& board, int wpsf, string words[], int tw){
    if(wpsf == tw){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                cout << board[i][j] << " ";
            }

            cout << endl;
        }

        return;
    }

    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            // horizontal
            if(canPlaceH(board, i, j, words[wpsf])){
                bool reset[words[wpsf].size()];
                // cout << sizeof(reset) / sizeof(bool);
                for(int x = 0; x < words[wpsf].size(); x++){
                    reset[x] = false;
                }

                placeH(board, i, j, words[wpsf], reset);
                crossword(board, wpsf+1, words, tw);
                unplaceH(board, i, j, words[wpsf], reset);          
            }

            // vertical
            if(canPlaceV(board, i, j, words[wpsf])){
                bool reset[words[wpsf].size()];
                
                for(int x = 0; x < words[wpsf].size(); x++){
                    reset[x] = false;
                }

                placeV(board, i, j, words[wpsf], reset);
                crossword(board, wpsf+1, words, tw);
                unplaceV(board, i, j, words[wpsf], reset);
            }
        }     
    }
}

int main(int argc, char** argv){
    vector<string> cross = {
        {"+-++++++++"},
        {"+-++++++++"},
        {"+-------++"},
        {"+-++++++++"},
        {"+-++++++++"},
        {"+------+++"},
        {"+-+++-++++"},
        {"+++++-++++"},
        {"+++++-++++"},
        {"++++++++++"}
    };
    
    string words[] = {"GWALIOR", "NORWAY", "ENGLAND", "AGRA"};

    crossword(cross, 0, words, 4);
}