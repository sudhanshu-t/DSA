#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isQueenSafe(vector<vector<int>>& board, int r, int c){
    // Row Check
    for(int j = 0; j < board[r].size(); j++){
        if(j != c && board[r][j] == 1){
            return false;
        }
    }

    // Col Check
    for(int i = 0; i < board.size(); i++){
        if(i != r && board[i][c] == 1){
            return false;
        }
    }

    // NE
    for(int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++){
        if(board[i][j] == 1){
            return false;
        }
    }

    // NW
    for(int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 1){
            return false;
        }
    }

    // SE
    for(int i = r + 1, j = c + 1; i < board.size() && j < board.size(); i++, j++){
        if(board[i][j] == 1){
            return false;
        }
    }

    // SW
    for(int i = r + 1, j = c - 1; i < board.size() && j >= 0; i++, j--){
        if(board[i][j] == 1){
            return false;
        }
    }

    return true;
}

// Proactive n queen do not require isBoardSafe(), 
// since every q is placed safely, 
// hence no need to check the final arrangement in BC

int count = 0;
void queen_level_i_j(vector<vector<int>>& board, int tq, int cq, int lui, int luj){
    if(cq == tq){
        count++;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        return;
    }

    int cr, cc;

    cr = (luj == board.size() - 1) ? lui + 1 : lui;
    cc = (luj + 1) % board.size();

    for(int i = cr; i < board.size(); i++){
        for(int j = (i == cr) ? cc : 0; j < board[i].size(); j++){
            if(board[i][j] != 1 && isQueenSafe(board, i, j)){
                board[i][j] = 1;
                queen_level_i_j(board, tq, cq + 1, i, j);
                board[i][j] = 0;
            }
        }
    }
}

int main(int argc, char** argv){
    vector<vector<int>> board (4, vector<int> (4, 0));

    queen_level_i_j(board, 4, 0, 0, -1);

    cout << count << endl;
}