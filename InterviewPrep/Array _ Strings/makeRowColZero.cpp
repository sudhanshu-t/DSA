#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int> > &A) {
    bool r = true, c = true;
    
    for(int j = 0; j < A[0].size(); j++){
        if(A[0][j] == 0){
            r = false;
            break;
        }
    }
    
    for(int i = 0; i < A.size(); i++){
        if(A[i][0] == 0){
            c = false;
            break;
        }
    }
    
    for(int j = 1; j < A[0].size(); j++){
        for(int i = 0; i < A.size(); i++){
            if(A[i][j] == 0){
                A[0][j] = -1;
                break;
            }
        }
    }
    
    for(int i = 1; i < A.size(); i++){
        for(int j = 0; j < A[0].size(); j++){
            if(A[i][j] == 0){
                A[i][0] = -1;
            }
        }
    }
    
    for(int j = 1; j < A[0].size(); j++){
        if(A[0][j] == -1){
            for(int i = 0; i < A.size(); i++){
                A[i][j] = 0;
            }
        }
    }
    
    for(int i = 1; i < A.size(); i++){
        if(A[i][0] == -1){
            for(int j = 0; j < A[0].size(); j++){
                A[i][j] = 0;
            }
        }
    }
    
    if(r == false){
        for(int j = 0; j < A[0].size(); j++){
            A[0][j] = 0;
        }
    }

    if(c == false){
        for(int i = 0; i < A.size(); i++){
            A[i][0] = 0;
        }
    }
    
    // unordered_set<int> rows;
    // unordered_set<int> cols;
    
    // for(int i = 0; i < A.size(); i++){
    //     for(int j = 0; j < A[0].size(); j++){
    //         if(A[i][j] == 0){
    //             rows.insert(i);
    //             cols.insert(j);
    //         }
    //     }
    // }
    
    // for(int i = 0; i < A.size(); i++){
    //     for(int j = 0; j < A[0].size(); j++){
    //         if(rows.find(i) != rows.end() ||
    //           cols.find(j) != cols.end()){
    //             A[i][j] = 0;
    //         }
    //     }
    // }
}

int main(){
    vector<vector<int>> A = {
        {0,0},
        {1,0}
    };

    setZeroes(A);

    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[0].size(); j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
