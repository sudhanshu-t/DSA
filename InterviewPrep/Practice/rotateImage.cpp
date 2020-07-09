#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    for(int i = 0; i < matrix.size(); i++){
        for(int j = i; j < matrix[0].size(); j++){
            if(i == j){
                continue;
            }
            
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size() / 2; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrix[0].size() - j - 1];
            matrix[i][matrix[0].size() - j - 1] = temp;
        }
    }

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int>> mat = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    rotate(mat);
}