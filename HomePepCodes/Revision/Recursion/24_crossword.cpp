#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canPlaceH(vector<string>& board, int i, int j, string word){
    if(j + word.size() > board.size()){
        return false;
    } else if(j-1 >= 0 && board[i][j-1] != '+'){
        return false;
    } else if(j + word.size() < board.size() && board[i][j + word.size()] != '+'){
        return false;
    }
    
    for(int jj = j; jj < j + word.size() && jj < board[i].size(); jj++){
        if(board[i][jj] == '-' || board[i][jj] == word[jj - j]){
            continue;
        } else {
            return false;
        }
    }
    
    return true;
}

void placeH(vector<string>& board, int i, int j, string word, vector<bool>& helper){
    for(int jj = j; jj < j + word.size() && jj < board[i].size(); jj++){
        if(board[i][jj] == '-'){
            helper[jj - j] = true;
            board[i][jj] = word[jj - j];
        }
    }
}

void unplaceH(vector<string>& board, int i, int j, string word, vector<bool>& helper){
    for(int jj = j; jj < j + word.size() && jj < board[i].size(); jj++){
        if(helper[jj - j] == true){
            board[i][jj] = '-';
        }
    }
}

bool canPlaceV(vector<string>& board, int i, int j, string word){
    if(i + word.size() > board.size()){
        return false;
    } else if(i-1 >= 0 && board[i-1][j] != '+'){
        return false;
    } else if(i + word.size() < board.size() && board[i + word.size()][j] != '+'){
        return false;
    }

    for(int ii = i; ii < i + word.size() && ii < board.size(); ii++){
        if(board[ii][j] == '-' || board[ii][j] == word[ii - i]){
            continue;
        } else {
            return false;
        }
    }
    return true;
}

void placeV(vector<string>& board, int i, int j, string word, vector<bool>& helper){
    for(int ii = i; ii < i + word.size() && ii < board.size(); ii++){
        if(board[ii][j] == '-'){
            helper[ii - i] = true;
            board[ii][j] = word[ii - i];
        }
    }
}

void unplaceV(vector<string>& board, int i, int j, string word, vector<bool>& helper){
    for(int ii = i; ii < i + word.size() && ii < board.size(); ii++){
        if(helper[ii - i] == true){
            board[ii][j] = '-';
        }
    }
}

void crossword(vector<string>& board, int wpsf, vector<string>& words){
    if(wpsf == words.size()){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        return;
    }

    string word = words[wpsf];

    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(canPlaceH(board, i, j, word)){
                vector<bool> helper (word.size(), false);
                placeH(board, i, j, word, helper);
                crossword(board, wpsf+1, words);
                unplaceH(board, i, j, word, helper);
            } else if(canPlaceV(board, i, j, word)){
                vector<bool> helper (word.size(), false);
                placeV(board, i, j, word, helper);
                crossword(board, wpsf+1, words);
                unplaceV(board, i, j, word, helper);
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
    
    vector<string> words = {"GWALIOR", "NORWAY", "ENGLAND", "AGRA"};

    vector<string> board = {
        {"++++++-+++"},
        {"++------++"},
        {"++++++-+++"},
        {"++++++-+++"},
        {"+++------+"},
        {"++++++-+-+"},
        {"++++++-+-+"},
        {"++++++++-+"},
        {"++++++++-+"},
        {"++++++++-+"}
    };

    vector<string> words2 = {"ICELAND","MEXICO", "PANAMA", "ALMATY"};


    crossword(board, 0, words2);
}