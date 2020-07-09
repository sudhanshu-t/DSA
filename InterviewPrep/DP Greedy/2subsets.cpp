#include <bits/stdc++.h>
using namespace std;

// vector<int> s1;
// vector<int> s2;

vector<vector<int>> divide(vector<int>& arr, int idx){
    if(idx == arr.size()-2){
        vector<int> s1, s2;
        if(arr[idx] < 0 || arr[idx+1] < 0){
            s1.push_back(arr[idx]);
            s1.push_back(arr[idx+1]);
        } else {
            s1.push_back(arr[idx]);
            s2.push_back(arr[idx+1]);
        }
        vector<vector<int>> bres (2);
        bres[0] = s1;
        bres[1] = s2;
        return bres;
    }

    vector<vector<int>> rres = divide(arr, idx+1);
    int s1Sum = 0;
    for(int i = 0; i < rres[0].size(); i++){
        s1Sum += rres[0][i];
    }

    int s2Sum = 0;
    for(int i = 0; i < rres[1].size(); i++){
        s2Sum += rres[1][i];
    }

    if(arr[idx] > 0){
        if(s1Sum < s2Sum){
            rres[0].push_back(arr[idx]);
        } else {
            rres[1].push_back(arr[idx]);
        }
    } else {
        if(s1Sum > s2Sum){
            rres[0].push_back(arr[idx]);
        } else {
            rres[1].push_back(arr[idx]);
        }
    }

    return rres;
}

int main(){
    vector<int> arr ={1,-2,3,-4,5,-9,10};
    vector<vector<int>> res = divide(arr, 0);
    for(int i = 0; i < res[0].size(); i++){
        cout << res[0][i] << " ";
    }
    cout << endl;
    
    for(int i = 0; i < res[1].size(); i++){
        cout << res[1][i] << " ";
    }
    cout << endl;
}