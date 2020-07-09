#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>

using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array and k occurunces.
// Print id of customer which will be served first.
void solve(vector<int>& arr,int k) {
// write your code here.
    unordered_map<int, int> map;
    for(int i = 0; i < arr.size(); i++){
        map[arr[i]]++;
    }

    for(int i = 0; i < arr.size(); i++){
        if(map[arr[i]] == k){
            cout << arr[i] << endl;
            return;
        }
    }

    cout << -1 << endl;
}

//Don't make any changes here

int main(int argc,char** argv){

    int n,k;
    cin>>n;
    cin>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    solve(v,k);
}