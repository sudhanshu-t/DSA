#include <iostream>
#include <string>
#include <vector>

#define vb vector<bool>
#define vvb vector<vb>

using namespace std;

int counter = 0;

int db = 0;

bool isTheQueenSafe(vvb& board, int r, int c){
    // Row check
    for(int i = 0; i < board.size(); i++){
        if(board[r][i] == true){
            return false;
        }
    }

    // Col check
    for(int i = 0; i < board.size(); i++){
        if(board[i][c] == true){
            return false;
        }
    }

    // Diag check

    // SE
    for(int i = r+1, j = c+1; i < board.size() && j < board.size(); i++, j++){
        if(board[i][j] == true){
            return false;
        }
    }

    // SW
    for(int i = r+1, j = c-1; i < board.size() && j >= 0; i++, j--){
        if(board[i][j] == true){
            return false;
        }
    }

    // NW
    for(int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == true){
            return false;
        }
    }

    // NE
    for(int i = r-1, j = c+1; i >= 0 && j < board.size(); i--, j++){
        if(board[i][j] == true){
            return false;
        }
    }

    return true;
}

bool isTheKnightSafe(vvb& board, int i, int j){
    if(i-2 >= 0 && j+1 < board.size()
        && board[i-2][j+1] == true){
            return false;
    }

    if(i-2 >= 0 && j-1 >= 0
        && board[i-2][j-1] == true){
            return false;
    }

    if(i-1 >= 0 && j+2 < board.size()
        && board[i-1][j+2] == true){
            return false;
    }

    if(i-1 >= 0 && j-2 >= 0
        && board[i-1][j-2] == true){
            return false;
    }

    if(i+2 < board.size() && j+1 < board.size()
        && board[i+2][j+1] == true){
            return false;
    }

    if(i+2 < board.size() && j-1 >= 0
        && board[i+2][j-1] == true){
            return false;
    }

    if(i+1 < board.size() && j+2 < board.size()
        && board[i+1][j+2] == true){
            return false;
    }

    if(i+1 < board.size() && j-2 >= 0
        && board[i+1][j-2] == true){
            return false;
    }
 
    return true;
}

bool isTheBoardSafe(vvb& board){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            
            if(board[i][j]==true){
                if(isTheQueenSafe(board, i, j) != true){
                    return false;
                }
            }
        }
    }

    return true;
}

void nq_npr_q(vvb& board, int cq, string asf){
    if(cq > board.size()){
        counter++;
        cout << asf << endl;
        return;
    }
    
    for(int i = 0; i < board.size() * board.size(); i++){
        int r = i / board.size();
        int c = i % board.size();

        if(board[r][c] == false && isTheQueenSafe(board,r,c) == true){
            board[r][c] = true;
            nq_npr_q(board, cq+1, asf + "b" + to_string(i) + "q" + to_string(cq) + " ");
            board[r][c] = false;
        }
    }
}

void nq_ncr_q(vvb& board, int cq, int lqb, string asf){
    if(cq > board.size()){
        counter++;
        cout << asf << endl;
        return;
    }
    
    for(int i = lqb; i < board.size() * board.size(); i++){
        int r = i / board.size();
        int c = i % board.size();

        if(board[r][c] == false && isTheQueenSafe(board,r,c) == true){
            board[r][c] = true;
            nq_ncr_q(board, cq+1, i+1, asf + "b" + to_string(i) + "q" + to_string(cq) + " ");
            board[r][c] = false;
        }
    }
}

void nq_ncr_b(vvb& board, int bno, int qpsf, string asf){
    if(bno == board.size() * board.size()){
        if(qpsf == board.size()){
            cout << asf << endl;
            counter++;
        }
        return;
    }

    int r = bno / board.size();
    int c = bno % board.size();

    nq_ncr_b(board, bno+1, qpsf, asf);

    if(isTheQueenSafe(board, r, c)){// No need to check if box is vacant in combinations since no box is visited twice
        board[r][c] = true;
        nq_ncr_b(board, bno+1, qpsf+1, asf + "b" + to_string(bno) + "q" + to_string(qpsf) + " ");
        board[r][c] = false;
    }
}

void nq_npr_b(vvb& board, int bno, int qpsf[], int tq, string asf){
    if(bno == board.size() * board.size()){
        for(int i = 0; i < tq; i++){
            if(qpsf[i] == 0){
                return;
            }
        }
        counter++;
        cout << asf << endl;
        return;
    }

    nq_npr_b(board, bno+1, qpsf, tq, asf);

    int r = bno / board.size();
    int c = bno % board.size();

    for(int i = 0; i < tq; i++){
        if(qpsf[i] == 0 && isTheQueenSafe(board, r, c)){
            qpsf[i] = 1;
            board[r][c] = 1;

            nq_npr_b(board, bno+1, qpsf, tq, asf + "B" + to_string(bno) + "Q" + to_string(i) + " ");

            qpsf[i] = 0;
            board[r][c] = 0;
        }
    }
}

void nk_ncr_b(vvb& board, int bno, int qpsf, string asf){
    if(bno == board.size() * board.size()){
        if(qpsf == board.size()){
            cout << asf << endl;
            counter++;
        }
        return;
    }

    int r = bno / board.size();
    int c = bno % board.size();

    nk_ncr_b(board, bno+1, qpsf, asf);

    if(isTheKnightSafe(board, r, c)){// No need to check if box is vacant in combinations since no box is visited twice
        board[r][c] = true;
        nk_ncr_b(board, bno+1, qpsf+1, asf + "b" + to_string(bno) + "q" + to_string(qpsf) + " ");
        board[r][c] = false;
    }
}

// void nq_npr_b(vvb& board, int qpsf, int bno, string asf){
//     if(bno == board.size() * board.size()){
//         // if(qpsf == board.size()){
//         //     cout << asf << endl;
//         //     counter++;
//         // }
//         counter++;
//         cout << asf << endl;
//         return;
//     }

//     int r = bno / board.size();
//     int c = bno % board.size();

//     nq_npr_b(board, qpsf, bno+1, asf);

//     if(board[r][c] == false && isTheQueenSafe(board, r, c)){
//         board[r][c] = true;
//         nq_npr_b(board, qpsf + 1, bno+1, asf + "b" + to_string(bno) + "q" + to_string(qpsf) + " ");
//         board[r][c] = false;
//     }
// }

int main(int argc, char** argv){
    vvb board = {
        {false, false, false, false},
        {false, false, false, false},
        {false, false, false, false},
        {false, false, false, false}
    };

    // nq_npr_q(board, 1, "");
    // cout << counter << endl;
    // nq_ncr_q(board, 1, 0, "");

    // nq_ncr_b(board, 0, 0, "");
    // cout << counter << endl;

    // nq_npr_b(board, 0, 1, "");
    // cout << counter << endl;

    // vvb board2 = {
    //     {false, false, false},
    //     {false, false, false},
    //     {false, false, false}
    // };

    // nk_ncr_b(board2, 0, 0, "");

    int qpsf[] = {0};
    nq_npr_b(board, 0, qpsf, 4, "");
    cout << counter << endl;
}