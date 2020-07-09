#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> res;

bool isSudokuSafe(vector<vector<char>>& board, int x, int y, char key){
    // row
    for(int j = 0; j < 9; j++){
        if(board[x][j] == key){
            return false;
        }
    }
    
    // col
    for(int i = 0; i < 9; i++){
        if(board[i][y] == key){
            return false;
        }
    }
    
    // grids
    int rc = (x/3)*3;
    int cc = (y/3)*3;
    for(int i = rc; i < rc+3; i++){
        for(int j = cc; j < cc+3; j++){
            if(board[i][j] == key){
                return false;
            }
        }
    }
    
    return true;
}

void helper(vector<vector<char>>& board, int bno){
    if(bno == board.size()*board.size()){
        res = board;
        return;
    }
    
    int i = (bno) / 9;
    int j = (bno) % 9;
    
    
    if(board[i][j] != '.'){
        helper(board, bno+1);
        return;
    }

    for(int k = 1; k <= 9; k++){
        if(isSudokuSafe(board, i, j, k+'0')){
            board[i][j] = k + '0';
            helper(board, bno+1);
            board[i][j] = '.';
        }
    }
}

void solveSudoku(vector<vector<char>>& board) {
    helper(board, 0);
    board = res;
}

int main(){
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solveSudoku(board);

    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}