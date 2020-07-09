#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Slot {
public:
    int row;
    int col;
    int length;
    bool isV;
    
    Slot(int r, int c, int l, bool isV) {
        row = r;
        col = c;
        length = l;
        this->isV = isV;
    }
};

vector<Slot*> slots;

vector<vector<char>> board {
        {'+','+','+','+','+'},
        {'-','-','-','+','+'},
        {'-','+','+','-','-'},
        {'-','+','+','+','+'},
        {'+','-','-','-','+'}
};

vector<string> words = {"and", "ant", "to"};

void setSlots() {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == '-') {
                if (i - 1 >= 0 && board[i - 1][j] == '+') {
                    int l = 0;

                    while (i + l < board.size() && board[i + l][j] == '-') {
                        l++;
                    }

                    if (l > 1) {
                        Slot *slot = new Slot(i, j, l, true);
                        slots.push_back(slot);
                    }
                }
                
                if (j - 1 >= 0 && board[i][j - 1] == '+') {
                    int l = 0;

                    while (j + l < board[0].size() && board[i][j + l] == '-') {
                        l++;
                    }

                    if (l > 1) {
                        Slot *slot = new Slot(i, j, l, false);
                        slots.push_back(slot);
                    }
                }
            }
        }
    }
}

int counter = 0;

void display() {
    counter++;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool canPlaceH(int r, int c, string word){
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

void placeH(int r, int c, string word, bool reset[]){
    for(int j = c; j < c+word.size(); j++){
        if(board[r][j] == '-'){
            reset[j-c] = true;
        }

        board[r][j] = word[j-c];
    }
}

void unPlaceH(int r, int c, string word, bool reset[]){
    // cout << '7' << endl;
    for(int j = c; j < c+word.size(); j++){
        if(reset[j-c] == true){
            board[r][j] = '-';
        }
    }
}

bool canPlaceV(int r, int c, string word){
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

void placeV(int r, int c, string word, bool reset[]){
    for(int i = r; i < r+word.size(); i++){
        if(board[i][c] == '-'){
            reset[i-r] = true;
        }

        board[i][c] = word[i-r];
    }
}

void unPlaceV(int r, int c, string word, bool reset[]){
    for(int i = r; i < r+word.size(); i++){
        if(reset[i-r] == true){
            board[i][c] = '-';
        }
    }
}

void crossword_si(int cs, int wpsf, bool itwp[]) {
    if(cs == slots.size()){
        if(wpsf == words.size())
            display();
        
        return;
    }

    crossword_si(cs + 1, wpsf, itwp);

    Slot *s = slots[cs];
    
    for (int i = 0; i < words.size(); i++) {
        if(itwp[i] == false){
            if(canPlaceV(s->row, s->col, words[i]) == true){
                bool reset[words[i].size()] = {false};
                itwp[i] = true;
                placeV(s->row, s->col, words[i], reset);
                crossword_si(cs+1, wpsf+1, itwp);
                unPlaceV(s->row, s->col, words[i], reset);
                itwp[i] = false;
            }

            if(canPlaceH(s->row, s->col, words[i]) == true){
                bool reset[words[i].size()] = {false};
                itwp[i] = true;
                placeH(s->row, s->col, words[i], reset);
                crossword_si(cs+1, wpsf+1, itwp);
                unPlaceH(s->row, s->col, words[i], reset);
                itwp[i] = false;
            }
        }
    }
    
}

int main(int argc, char **argv) {
    bool itwp[3] = {false};
    crossword_si(0, 0, itwp);

    cout << counter << endl;

    return 0;
}