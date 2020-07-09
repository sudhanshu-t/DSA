#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>

using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array,n length of array and k.
// It should print required output.
void solve(vector<int>& arr,int n,int k){
    //Write your code here
    unordered_map<int, int> map;

    for(int i = 0; i < arr.size(); i++){
        map[arr[i]]++;
    }

    int count = 0;

    for(int i = 0; i < arr.size(); i++){
        if(map[arr[i]] == 1){
            count++;
            if(count == k){
                cout << arr[i] << endl;
                return;
            }
        }
    }

    cout << "-1" << endl;
}

int main(int argc,char** argv){
    int n;
    cin>>n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    int k;
    cin>>k;
    solve(v,n,k);
}