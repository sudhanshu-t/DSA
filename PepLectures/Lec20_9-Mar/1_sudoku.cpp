#include <iostream>
#include <vector>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;

int count = 0;

int rbm[9];
int cbm[9];
int smbm[3][3];

bool isTheSudokuSafe(vvi& board, int r, int c, int key){
    // Row check
    for(int j = 0; j < board.size(); j++){
        if(board[r][j] == key){
            return false;
        }
    }

    // Col check
    for(int i = 0; i < board.size(); i++){
        if(board[i][c] == key){
            return false;
        }
    }

    // Grid check
    int cr = (r / 3) * 3;
    int cc = (c / 3) * 3;

    for(int i = cr; i < cr + 3 && i < board.size(); i++){
        for(int j = cc; j < cc + 3 && j < board.size(); j++){
            if(board[i][j] == key){
                return false;
            }
        }
    }

    // Else return true
    // count++;
    // cout << count << endl;
    // cout << r << c  << key << endl;
    return true;
}

void sudoku(vvi& board, int bno){
    if(bno == board.size() * board.size() - 1){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                cout << board[i][j] << " ";
            }

            cout << endl;
        }
        return;
    }

    int i = bno + 1;
    int r = i / board.size();
    int c = i % board.size();

    if(board[r][c] == 0){
        for(int j = 1; j <= 9; j++){
            if(isTheSudokuSafe(board, r, c, j)){
                board[r][c] = j;
                sudoku(board, i);
                board[r][c] = 0;
            }
        }
    }

    else{
        sudoku(board, i);
    }

    return;
}

int makeInputRow(vvi& board, int i){
    int bm = 0;
    for(int j = 0; j < board.size(); j++){
        int k = board[i][j];
        bm = bm | (1 << k);
    }

    return bm;
}

int makeInputCol(vvi& board, int j){
    int bm = 0;
    for(int i = 0; i < board.size(); i++){
        int k = board[i][j];
        bm = bm | (1 << k);
    }

    return bm;
}

int makeInputGrid(vvi& board, int i, int j){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int bm = 0;
            for(int j = 0; j < board.size(); j++){
                int k = board[i][j];
                bm = bm | (1 << k);
            }
        }
    }

    return bm;
}

bool isTheSudokuSafeBM(r, c, k){
    int bm = 1 << k;

    // Row Check
    if((rbm[r] & bm) == bm){
        return false;
    }

    // Col Check
    if((cbm[c] & bm) == bm){
        return false;
    }

    // Grid Check
    if((smbm[r/3][c/3] & bm) == bm){
        return false;
    }

    return true;
}

void sudoku_bm(vvi& board, int bno){
    if(bno == board.size() * board.size() - 1){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                cout << board[i][j] << " ";
            }

            cout << endl;
        }

        return;
    }

    int i = bno + 1;
    int r = i / board.size();
    int c = i % board.size();

    if(board[r][c] == 0){
        for(int k = 1; k <= 9; k++){
            if(isTheSudokuSafeBM(board, r, c, k)){
                board[r][c] = 1;
                sudoku_bm(board, i);
                board[r][c] = 0;
            }
        }
    }
    else {
        sudoku_bm(board, i);
    }
}

int main(int argc, char** argv){
    vvi board = {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };

    // sudoku(board, -1);

    for(int i = 0; i < 9; i++){
        rbm[i] = makeInputRow(board, i);
    }

    for(int i = 0; i < 9; i++){
        cbm[i] = makeInputCol(board, i);
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            smbm[i][j] = makeInputGrid(board, i, j);
        }
    }
    
    sudoku_bm(board, -1)
}