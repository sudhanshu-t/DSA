#include <iostream>
#include <string>
#include <vector>

#define vb vector<bool>
#define vvb vector<vb>

using namespace std;

static int counter = 0;

bool isTheQueenSafe(vvb& board, int i, int j){
    // horizontal check
    for(int jj = 0; jj < board.size(); jj++){
        if(board[i][jj] == true && jj != j){
            return false;
        }
    }

    // vertical check
    for(int ii = 0; ii < board.size(); ii++){
        if(board[ii][j] == true && ii != i){
            return false;
        }
    }

    // SE diagonal check
    for(int ii = i + 1, jj = j + 1;
        ii < board.size() && jj < board.size(); 
        ii++, jj++){
            if(board[ii][jj] == true){
                return false;
            }
    }

    // SW diagonal check
    for(int ii = i + 1, jj = j - 1;
        ii < board.size() && jj >= 0; 
        ii++, jj--){
            if(board[ii][jj] == true){
                return false;
            }
    }

    // NW diagonal check
    for(int ii = i - 1, jj = j - 1;
        ii >= 0 && jj >= 0; 
        ii--, jj--){
            if(board[ii][jj] == true){
                return false;
            }
    }

    // NE diagonal check
    for(int ii = i - 1, jj = j + 1;
        ii >= 0 && jj < board.size(); 
        ii--, jj++){
            if(board[ii][jj] == true){
                return false;
            }
    }

    return true;
}

bool isTheBoardSafe(vvb& board){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            if(board[i][j] == true){
                if(isTheQueenSafe(board, i, j) == false){
                    return false;
                }
            }
        }
    }

    return true;
}

// Reactive Approach
void nqueens(vvb& board, int cq, int lqi, int lqj, string asf){
    if(cq == board.size()){
        if(isTheBoardSafe(board) == true){
            cout << asf << endl;
            counter++;
        }

        return;
    }


    for(int i = lqi; i < board.size(); i++){
        for(int j = ((i == lqi) ? lqj + 1: 0); j < board.size(); j++){
            if(board[i][j] == false){
                board[i][j] = true;
                    nqueens(board, cq+1, i, j, asf + to_string(i) + to_string(j) + " ");
                board[i][j] = false;
            }
        }
    }
}

void nqueens2(vvb& board, int cq, int bno, string asf){
    if(cq == board.size()){
        cout << asf << endl;
        counter++;
        return;
    }

    for(int i = bno + 1; i < board.size()*board.size(); i++){
        int r = i / board.size();
        int c = i % board.size();

        if(board[r][c] == false && isTheQueenSafe(board, r, c)){
            board[r][c] = true;
            nqueens2(board, cq + 1, i, asf + to_string(r) + to_string(c) + " ");
            board[r][c] = false;
        }
    }
}

// Proactive Approach
void nqueens_pro(vvb& board, int cq, int lqi, int lqj, string asf){
    if(cq == board.size()){
        cout << asf << endl;
        counter++;

        return;
    }


    for(int i = lqi; i < board.size(); i++){
        for(int j = ((i == lqi) ? lqj + 1: 0); j < board.size(); j++){
            if(board[i][j] == false){
                board[i][j] = true;
                    if(isTheQueenSafe(board, i, j)){
                        nqueens_pro(board, cq+1, i, j, asf + to_string(i) + to_string(j) + " ");
                    }
                board[i][j] = false;
            }
        }
    }
}

// Using BM
void nqueens_bm(int bm, int cq, int cbno, int tq, string asf){
    if(cq == tq){
        cout << asf << endl;
        counter++;

        return;
    }

    
}

// Using Box choice approach
void nqueens_bc(vvb& board, int cb, int cq, int tq, string asf){
    if(cb == board.size() * board.size()){
        if(cq == tq){
            cout << asf << endl;
            counter++;
        }

        return;
    }

    int i = cb / board.size();
    int j = cb % board.size();

    if(board[i][j] == false){
        board[i][j] = true;

        if(isTheBoardSafe(board))
            nqueens_bc(board, cb + 1, cq + 1, tq, asf + to_string(i) + to_string(j) + " ");

        board[i][j] = false;
    }
    
    nqueens_bc(board, cb + 1, cq, tq, asf + "");
}

// Is knight safe check
bool isTheKSafe(vvb& board, int i, int j){
    if(i-2 >= 0 && j+1 < board.size() && board[i-2][j+1] == true){
        return false;
    }
    else if(i-2 >= 0 && j-1 >= 0 && board[i-2][j-1] == true){
        return false;
    }
    else if(i+2 < board.size() && j+1 < board.size() && board[i+2][j+1] == true){
        return false;
    }
    else if(i+2 < board.size() && j-1 >= 0 && board[i+2][j-1] == true){
        return false;
    }
    else if(i-1 >= 0 && j+2 < board.size() && board[i-1][j+2] == true){
        return false;
    }
    else if(i-1 >= 0 && j-2 >= 0 && board[i-1][j-2] == true){
        return false;
    }
    else if(i+1 < board.size() && j+2 < board.size() && board[i+1][j+2] == true){
        return false;
    }
    else if(i+1 < board.size() && j-2 >= 0 && board[i+1][j-2] == true){
        return false;
    }
    
    return true;
}

// Is Board Safe check for knights
bool isTheBoardSafeK(vvb& board){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            if(board[i][j] == true){
                if(isTheKSafe(board, i, j) == false){
                    return false;
                }
            }
        }
    }

    return true;
}

// N Knights
void nk(vvb& board, int ck, int lki, int lkj, string asf){
    if(ck == board.size()){
        if(isTheBoardSafeK(board) == true){
            cout << asf << endl;
            counter++;
        }

        return;
    }


    for(int i = lki; i < board.size(); i++){
        for(int j = ((i == lki) ? lkj + 1: 0); j < board.size(); j++){
            if(board[i][j] == false){
                board[i][j] = true;
                nk(board, ck+1, i, j, asf + to_string(i) + to_string(j) + " ");
                board[i][j] = false;
            }
        }
    }
}

int main(int argc, char** argv){
    vvb board = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    // Reactive approach

    // nqueens(board, 0, 0, -1, "");
    // cout << counter << endl;
    nqueens2(board, 0, -1, "");
    cout << counter << endl;

    // Proactive approach - Hits the base case just twice, hence more efficient?
    // nqueens_pro(board, 0, 0, -1, "");
    // cout << counter << endl;

    // N-Queens using Bit-masking
    // nqueens_bm(0, 0, 15, 4, "");
    // cout << counter << endl;

    // Box choice approach
    // nqueens_bc(board, 0, 0, 4, "");
    // cout << counter << endl;

    // N Knights
    // vvb board1 = {
    //     {0,0,0},
    //     {0,0,0},
    //     {0,0,0},
    // };

    // nk(board1, 0, 0, -1, "");
    // cout << counter << endl;
    
}

