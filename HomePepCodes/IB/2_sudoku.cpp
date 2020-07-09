#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<char>>& A, int r, int c, char x){
    // Col Check
    for(int i = 0; i < A.size(); i++){
        if(A[i][c] == x){
            return false;
        }
    }

    // Row Check
    for(int j = 0; j < A.size(); j++){
        if(A[r][j] == x){
            return false;
        }
    }

    // Grid Check
    int gr = (r / 3) * 3;
    int gc = (c / 3) * 3;

    for(int i = gr; i < gr+3; i++){
        for(int j = gc; j < gc+3; j++){
            if(i != r && j != c && A[i][j] == x){
                return false;
            }
        }
    }

    return true;
}

void sudoku(vector<vector<char>>& ans, vector<vector<char>>& A, int bno){
    if(bno == A.size() * A.size() - 1){
        ans = A;
        return;
    }

    int r = bno / A.size();
    int c = bno % A.size();

    // for(int i = 0; i < A.size(); i++){
    //     for(int j = 0; j < A.size(); j++){
    //         cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "NPRE" << bno << endl;

    if(A[r][c] == '.'){
        for(int i = 1; i <= 9; i++){
            if(isSafe(A, r, c, i + '0')){
                A[r][c] = i + '0';
                sudoku(ans, A, bno + 1);
                A[r][c] = '.';
            }
        }
    } else {
        sudoku(ans, A, bno+1);
    }

    // cout << "NPOST" << bno << endl;
    
}

// void Solution::solveSudoku(vector<vector<char> > &A) {
//     // Do not write main() function.
//     // Do not read input, instead use the arguments to the function.
//     // Do not print the output, instead return values as specified
//     // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
// }

int main(int argc, char** argv){
    vector<vector<char>> ans;
    vector<vector<char>> A = {
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

    
    sudoku(ans, A, 0);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans.size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    // int ch = 9;
    // char c = ch + '0';
    // cout << c;
}
