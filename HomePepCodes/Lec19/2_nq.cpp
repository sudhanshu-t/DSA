#include <iostream>
#include <string>
#include <vector>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;

bool isTheQSafe(vvi& board, int r, int c){
    // Row check
    for(int j = 0; j < board.size(); j++){
        if(board[r][j] == 1 && j != c){
            return false;
        }
    }
    
    // Col check
    for(int i = 0; i < board.size(); i++){
        if(board[i][c] == 1 && i != r){
            return false;
        }
    }

    // Diag check
    // NE
    for(int i = r-1, j = c+1; i >= 0 && j < board.size(); i--, j++){
        if(board[i][j] == 1)
            return false;
    }

    // SE
    for(int i = r+1, j = c+1; i < board.size() && j < board.size(); i++, j++){
        if(board[i][j] == 1){
            return false;
        }
    }

    // SW
    for(int i = r+1, j = c-1; i < board.size() && j >= 0; i++, j--){
        if(board[i][j] == 1)
            return false;
    }

    // NW
    for(int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 1){
            return false;
        }
    }

    return true;
}

bool isTheBoardSafe(vvi& board){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == 1 && isTheQSafe(board, i, j) != true){
                return false;
            }
        }
    }

    return true;
}

// Boxes on level
void nq_pro(vvi& board, int bno, int cq, string asf){
    if(bno == board.size() * board.size()){
        // cout << "td" << endl;
        if(cq == board.size())
            cout << asf << endl;
        return;
    }

    int r = bno / board.size();
    int c = bno % board.size();

    if(board[r][c] == 0){
        board[r][c] = 1;
        if(isTheBoardSafe(board)){
            // cout << "Td" << endl;
            nq_pro(board, bno+1, cq+1, asf + to_string(r) + to_string(c) + " ");
        }
        board[r][c] = 0;
    }

    nq_pro(board, bno+1, cq, asf);
}

// Queens on level
void nq_pro_q(vvi& board, int cq, int bno, string asf){
    if(cq == board.size()){
        cout << asf << endl;
        return;
    }

    for(int i = bno+1; i < board.size() * board.size(); i++){
        int r = i / board.size();
        int c = i % board.size();

        if(board[r][c] == 0 && isTheQSafe(board, r, c)){
            // cout << "td" << endl;
            board[r][c] = 1;
            nq_pro_q(board, cq+1, i, asf + to_string(r) + to_string(c) + " ");
            board[r][c] = 0;
        }
    }
}

int main(int argc, char** argv){
    vvi board = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };

    nq_pro(board, 0, 0, "");
    // nq_pro_q(board, 0, -1, "");
}