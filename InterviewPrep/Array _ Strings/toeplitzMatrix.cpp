#include<iostream>
#include<vector>
using namespace std;

bool isToeplitzMatrix(vector<vector<int> >& matrix) {

    // for(int i = 0, j = 0; i < matrix.size() - 1 && j < matrix[0].size() - 1; i++, j++){
    //     if(matrix[i][j] != matrix[i+1][j+1]){
    //         return false;
    //     }
    // }

    int x = matrix.size() - 2;
    x = -x;
    // cout << x << endl;
    // cout << matrix[0].size() - 1 << endl;
    while(x < matrix[0].size() - 1){
        cout << x << endl;
        if(x < 0){
            for(int i = -x, j = 0; i < matrix.size() - 1 && j < matrix[0].size() - 1; i++, j++){
                cout << matrix[i][j] << " " << matrix[i+1][j+1] << endl;

                if(matrix[i][j] != matrix[i+1][j+1]){
                    return false;
                }
            }
        } else {
            for(int i = 0, j = x; i < matrix.size() - 1 && j < matrix[0].size() - 1; i++, j++){
                cout << matrix[i][j] << " " << matrix[i+1][j+1] << endl;
                if(matrix[i][j] != matrix[i+1][j+1]){
                    return false;
                }
            }
        }

        x++;
    }

    return true;
}

int main(int argc,char** argv) {
    int r ,c;
    cin>>r>>c;
    vector<vector<int>> mat (r,vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin>>mat[i][j];
        }
    }
    bool res=isToeplitzMatrix(mat);
    if(res==true){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}