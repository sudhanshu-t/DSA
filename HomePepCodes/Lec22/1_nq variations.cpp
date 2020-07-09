#include <iostream>
#include <vector>
#include <string>

#define vb vector<bool>
#define vvb vector<vb>

using namespace std;

int counter = 0;

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

// 1) nq_npr_q
void nq_npr_q(vvb& board, int cq, string asf){
    if(cq == board.size()){
        counter++;
        cout << asf << endl;
        return;
    }

    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            int b = i*board.size() + j;
            if(board[i][j] == false && isTheQueenSafe(board, i, j)){
                board[i][j] = true;
                nq_npr_q(board, cq+1, asf + "b" + to_string(b) + "q" + to_string(cq) + " ");
                board[i][j] = false;
            }
        }
    }
}

// 2) nq_ncr_q
void nq_ncr_q(vvb& board, int cq, int cb, string asf){
    if(cq == board.size()){
        counter++;
        cout << asf << endl;
        return;
    }

    // Incorrect Code

    int r = cb / board.size();
    int c = cb % board.size();

    for(int i = r; i < board.size(); i++){
        for(int j = ((i == r)?c:0); j < board.size(); j++){
            // int b = i*board.size() + j;
            if(board[i][j] == false && isTheQueenSafe(board, i, j)){
                board[i][j] = true;
                nq_ncr_q(board, cq+1, cb+1, asf + "b" + to_string(cb) + "q" + to_string(cq) + " ");
                board[i][j] = false;
            }
        }
    }

    // Correct Code

    // for(int i = cb; i < board.size() * board.size(); i++){
    //     int r = i / board.size();
    //     int c = i % board.size();

    //     if(board[r][c] == false && isTheQueenSafe(board, r, c) == true){
    //         board[r][c] = true;
    //         nq_ncr_q(board, cq+1, i+1, asf + "b" + to_string(i) + "q" + to_string(cq) + " ");
    //         board[r][c] = false;
    //     }
    // }
}

// 3) nq_ncr_b
void nq_ncr_b(vvb& board, int bno, int qpsf, string asf){
    if(bno == board.size() * board.size()){
        if(qpsf == board.size()){
            counter++;
            cout << asf << endl;
        }
        return;
    }

    int r = bno / board.size();
    int c = bno % board.size();

    nq_ncr_b(board, bno+1, qpsf, asf);

    if(board[r][c] == false && isTheQueenSafe(board, r, c) == true){
        board[r][c] = true;
        nq_ncr_b(board, bno+1, qpsf+1, asf + "b" + to_string(bno) + "q" + to_string(qpsf) + " ");
        board[r][c] = false;
    }
}

// 4) nq_npr_b
void nq_npr_b(vvb& board, int bno, int tq, string asf, bool qpsf[], int qsf){
    if(bno == board.size() * board.size()){
        // for(int i = 0; i < tq; i++){
        //     if(qpsf[i] == false){
        //         return;
        //     }
        // }

        if(qsf == tq){
            cout << asf << endl;
            counter++;
        }

        // counter++;
        // cout << asf << endl;
        return;
    }

    nq_npr_b(board, bno+1, tq, asf, qpsf, qsf);

    int r = bno / board.size();
    int c = bno % board.size();

    for(int i = 0; i < tq; i++){
        if(qpsf[i] == false && isTheQueenSafe(board, r, c) == true){
            qpsf[i] = true;
            board[r][c] = true;
            nq_npr_b(board, bno+1, tq, asf + "b" + to_string(bno) + "q" + to_string(i) + " ", qpsf, qsf+1);
            board[r][c] = false;
            qpsf[i] = false;
        }
    }
}

int main(int argc, char** argv){
    vvb board = {
        {false, false, false, false},
        {false, false, false, false},
        {false, false, false, false},
        {false, false, false, false}
    };

    // nq_npr_q(board, 0, "");
    // nq_ncr_q(board, 0, 0, "");
    // nq_ncr_b(board, 0, 0, "");

    bool qpsf[4];
    nq_npr_b(board, 0, 4, "", qpsf, 0);

    cout << counter << endl;

    // char ch = '2';
    // cout << ch - '0' << endl;

    return 0;
}