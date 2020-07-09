#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isQueenSafe(vector<string>& board, int r, int c){
    // Row Check
    for(int j = 0; j < c; j++){
        if(j != c && board[r][j] == 'Q')
            return false;
    }

    // NW Diag
    for(int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
            
    // SW Diag
    for(int i = r+1, j = c-1; i < board.size() && j >= 0; i++, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

void nQ_slave(vector<vector<string>>& ans, vector<string>& asf, int col, int tq){
    if(col == tq){
        // for(int i = 0; i < asf.size(); i++){
        //     cout << asf[i] << endl;
        // }

        ans.push_back(asf);

        return;
    }

    // cout << qpsf << endl;
    
    for(int i = 0; i < tq; i++){
        if(isQueenSafe(asf, i, col)){
            asf[i][col] = 'Q';
            // cout << r << c << endl;
            nQ_slave(ans, asf, col + 1, tq);
            asf[i][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int A) {
    vector<vector<string>> ans;
    vector<string> asf(A, "");
    nQ_slave(ans, asf, 0, 4);
}

int main(){
    vector<vector<string>> ans;
    int A = 1;
    string s;
    for(int i = 0; i < A; i++){
        s += '.';
    }

    // cout << s;
    vector<string> asf(A, s);
    nQ_slave(ans, asf, 0, A);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << endl;
        }

        cout << endl;
    }
}