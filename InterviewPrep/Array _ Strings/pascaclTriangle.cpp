#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solve(int A) {
    vector<vector<int>> res;

    if(A == 0){
        return res;
    }
    
    vector<int> first = {1};
    res.push_back(first);
    
    for(int i = 1; i < A; i++){
        vector<int> temp;
        for(int j = 0; j <= i; j++){
            int val = ((j-1 >= 0) ? res[i-1][j-1] : 0) + ((j >= 0) ? res[i-1][j] : 0);
            temp.push_back(val);
        }

        // cout << temp.size() << endl;
        res.push_back(temp);
        // cout << res[i].size() << endl;
        // for(int j = 0; j < res[i].size(); j++){
        //     cout << res[i][j] << " ";
        // }
        // cout << endl;
    }

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return res;
}

int main(int agrc, char** argv){
    vector<vector<int>> A = solve(4);

    // for(int i = 0; i < A.size(); i++){
    //     for(int j = 0; j < A[0].size(); j++){
    //         cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}