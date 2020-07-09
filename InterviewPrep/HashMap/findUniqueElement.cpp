#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array and n length of array.
// It should return a boolean value.
void solve(vector<int>& arr,int k) {
// write your code here.
    unordered_map<int, int> map;

    for(int i = 0; i < arr.size(); i++){
        map[arr[i]]++;
    }

    for(auto itr : map){
        if(itr.second != k){
            cout << itr.first;
            return;
        }
    }
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