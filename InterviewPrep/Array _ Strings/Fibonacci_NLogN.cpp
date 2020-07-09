#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B){
    vector<vector<int>> C(A.size(), vector<int> (A[0].size()));

    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[0].size(); j++){
            for(int k = 0; k < B.size(); k++){
                C[i][j] == A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

vector<vector<int>> power(vector<vector<int>>& M, int n){
    if(n == 1){
        return M;
    }

    vector<vector<int>> Mn2 = power(M, n/2);

    if(n % 2 == 0){
        return multiply(Mn2, Mn2);
    } else {
        return multiply(multiply(Mn2, Mn2), M);
    }
}

int main(int argc, char** argv){
    
}