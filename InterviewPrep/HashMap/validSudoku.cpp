#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input a 2D array of characters. It should return true if the
// board is valid, else should return false.
bool isValidSudoku(vector<vector<char> > board) {
    // write your code here.
    vector<int> row (9, 0);
    vector<int> col (9, 0);
    vector<int> grid (9, 0);

    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] != '.'){
                int n = board[i][j] - '0';
                int bm = (1 << n);
                // cout << bm << endl;
                if((row[i] & bm) == 0){
                    row[i] |= (1 << n);
                } else {
                    // cout << "1 -- " << endl;                    
                    return false;
                }
            }
        }

        // std::string binary = std::bitset<8>(128).to_string();
        // cout << binary << endl;
    }

    for(int j = 0; j < board[0].size(); j++){
        for(int i = 0; i < board.size(); i++){
            if(board[i][j] != '.'){
                int n = board[i][j] - '0';
                // cout << "val is " << n;
                int bm = 1 << n;
                if((bm & col[j]) == 0){
                    col[j] |= (1 << n);
                } else {
                    // cout << "2 -- " << i << j << endl;
                    return false;
                }
            }
        }
    }

    for(int i = 0; i < grid.size(); i++){
        int cr = (i / 3) * 3;
        int cc = (i % 3) * 3;

        for(int r = cr; r < cr + 3; r++){
            for(int c = cc; c < cc + 3; c++){
                if(board[r][c] != '.'){
                    int n = board[r][c] - '0';
                    int bm = 1 << n;
                    if((grid[i] & bm) == 0){
                        grid[i] |= (1 << n);
                    } else {
                        // cout << "3 -- " << endl;
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main(int argc, char** argv){
    vector<vector<char> > board(9, vector<char> (9));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin>>board[i][j];
        }
    }
    if (isValidSudoku(board)) {
        cout<<"Valid";
    } else {
        cout<<"Invalid";
    }

}