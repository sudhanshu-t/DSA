#include <iostream>
#include <string>
#include <vector>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;

bool canPlaceH(vector<string> board, int r, int c, string word){
    if(c + word.size() > board.size()){
        return false;
    }

    else if(c > 0 && board[r][c-1] != '+'){
        return false;
    }

    else if(c + word.size() <= board.size() && 
            board[r][c + word.size()] != '+'){
        return false;
    }

    else{
        for(int i = r, j = c; j < c+ word.size(); j++){
            if(board[i][j] != '-' && board[i][j] != word[j-c]){
                return false;
            }
        }
    }

    return true;
}

bool canPlaceV(vector<string> board, int r, int c, string word){
    if(r + word.size() > board.size()){
        return false;
    }

    else if(r > 0 && board[r-1][c] != '+'){
        return false;
    }

    else if(r + word.size() <= board.size() &&
            board[r + word.size()][c] != '+'){
        return false;
    }

    else {
        for(int i = r, j = c; i < r+word.size(); i++){
            if(board[i][j] != '-' && board[i][j] != word[i-r]){
                return false;
            }
        }
    }

    return true;
}

void placeH(vector<string> board, int r, int c, string word, bool reset[]){
    for(int i = r, j = c; j < c+word.size(); j++){
        if(board[i][j] == '-'){
            reset[j-c] = false;
        }
        board[i][j] = word[j - c];
    }
}

void placeV(vector<string> board, int r, int c, string word, bool reset[]){
    for(int i = r, j = c; i < r+word.size(); i++){
        if(board[i][j] == '-'){
            reset[i-r] = false;
        }
        board[i][j] = word[i - r];
    }
}

void unplaceH(vector<string> board, int r, int c, string word, bool reset[]){
    for(int i = r, j = c; j < c+word.size(); j++){
        if(reset[j - c] == false){
            board[i][j] = '-';
        }
    }
}

void unplaceV(vector<string> board, int r, int c, string word, bool reset[]){
    for(int i = r, j = c; i < r+word.size(); i++){
        if(reset[i - r] == false){
            board[i][j] = '-';
        }
    }
}

void crossword(vector<string> board, string words[], int wpsf, int tw){
    if(wpsf == tw){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                cout << board[i][j] << " ";
            }

            cout << endl;
        }            
        cout << endl;

        return;
    }

    cout << wpsf << endl;

    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            if(board[i][j] == '-' || board[i][j] == words[wpsf][0]){
                if(canPlaceH(board, i, j, words[wpsf])){
                    bool reset[words[wpsf].size()];

                    for(int i = 0; i < words[wpsf].size(); i++){
                        reset[i] = true;
                    }

                    placeH(board, i, j, words[wpsf], reset);
                    crossword(board, words, wpsf+1, tw);
                    unplaceH(board, i, j, words[wpsf], reset);
                }

                if(canPlaceV(board, i, j, words[wpsf])){
                    bool reset[words[wpsf].size()] = {true};

                    for(int i = 0; i < words[wpsf].size(); i++){
                        reset[i] = true;
                    }
                    
                    placeV(board, i, j, words[wpsf], reset);
                    crossword(board, words, wpsf+1, tw);
                    unplaceV(board, i, j, words[wpsf], reset);
                }
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

    crossword(cross, words, 0, 4);

    cout << endl;
}