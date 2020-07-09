#include <iostream>
#include <vector>

using namespace std;

bool isSudokuSafe(vector<vector<int>>& board, int n, int r, int c){
    // Row Check
    for(int j = 0; j < board.size(); j++){
        if(j != c && board[r][j] == n){
            return false;
        }
    }

    // Column Check
    for(int i = 0; i < board.size(); i++){
        if(i != r && board[i][c] == n){
            return false;
        }
    }

    // Grid Check

    int i = (r / 3) * 3;
    int j = (c / 3) * 3;

    for(int ii = i; ii < i + 3; ii++){
        for(int jj = j; jj < j + 3; jj++){
            if(ii != r && jj != c && board[ii][jj] == n){
                return false;
            }
        }
    }

    return true;
}

// Keeping boxes on levels - Bad complexity
void sudoku(vector<vector<int>>& board, int bno){
    if(bno == board.size() * board.size()){
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
        for(int n = 1; n <= 9; n++){
            if(isSudokuSafe(board, n, r, c)){
                board[r][c] = n;
                sudoku(board, i);
                board[r][c] = 0;
            }
        }
    } else {
        sudoku(board, i);
    }
}

/// Keeping numbers on levels - Better Complexity
void sudoku_num_levels(vector<vector<int>>& board, int num){
    if(num > 9){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        return;
    }

    for(int b = 0; b < board.size() * board.size(); b++){
        int r = b / board.size();
        int c = b % board.size();

        if(board[r][c] == 0 && isSudokuSafe(board, num, r, c)){
            board[r][c] = num;
            sudoku_num_levels(board, num + 1);
            board[r][c] = 0;

            // sudoku_num_levels(board, num);
        }
    }
}

int main(int argc, char** argv){
    vector<vector<int>> board = {
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
    sudoku_num_levels(board, 1);
}