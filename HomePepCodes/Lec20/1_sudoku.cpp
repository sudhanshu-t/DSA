#include <iostream>
#include <vector>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;

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

    for(int i = cr; i < cr+3; i++){
        for(int j = cc; j < cc+3; j++){
            if(board[i][j] == key){
                return false;
            }
        }
    }

    return true;
}

void sudoku(vvi& board, int bno){
    if(bno == board.size() * board.size()-1){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
        return;
    }

    int r = (bno+1) / board.size();
    int c = (bno+1) / board.size();
    
    if(board[r][c] == 0){
        for(int i = 1; i <= 9; i++){
            if(isTheSudokuSafe(board, r, c, i)){
                board[r][c] = i;
                sudoku(board, bno+1);
                board[r][c] = 0;
            }
        }
    }

    else{
        sudoku(board, bno+1);
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

    sudoku(board, -1);
}