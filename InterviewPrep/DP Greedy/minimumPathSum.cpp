#include<iostream>
#include<vector>
using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input a 2D array
// It should return the required output

int maze(vector<vector<int>> &m) {
    int ov = m[0][0];
    for(int i = m.size() - 1; i >= 0; i--){
        for(int j = m[0].size() - 1; j >= 0; j--){
            if(i + 1 < m.size() && j + 1 < m[0].size()){
                m[i][j] += min(m[i+1][j], m[i][j+1]);
            } else if(i + 1 < m.size()){
                m[i][j] += m[i+1][j];
            } else if(j + 1 < m[0].size()){
                m[i][j] += m[i][j+1];
            }
        }
    }

    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[0].size(); j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    return m[0][0];
}

int main(int argc,char**argv){
    int r,c;
    cin>>r>>c;
    vector< vector<int> >A(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>A[i][j];
        }
    }   
    cout<<maze(A)<<endl;
}