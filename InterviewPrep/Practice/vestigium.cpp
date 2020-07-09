#include <bits/stdc++.h>
using namespace std;

void vest(vector<vector<int>>& mat){
    int trace = 0;
    for(int i = 0; i < mat.size(); i++){
        trace += mat[i][i];
    }

    int dr = 0;
    for(int i = 0; i < mat.size(); i++){
        unordered_set<int> set;
        for(int j = 0; j < mat[0].size(); j++){
            if(set.find(mat[i][j]) == set.end()){
                set.insert(mat[i][j]);
            } else {
                dr++;
                break;
            }
        }
    }

    int dc = 0;
    for(int j = 0; j < mat[0].size(); j++){
        unordered_set<int> c;
        for(int i = 0; i < mat.size(); i++){
            if(c.find(mat[i][j]) == c.end()){
                c.insert(mat[i][j]);
            } else {
                dc++;
                break;
            }
        }
    }

    cout << trace << " " << dr << " " << dc;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> mat (n, vector<int> (n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int num;
                cin >> num;
                mat[i][j] = num;
            }
        }

        vest(mat);
    }
}