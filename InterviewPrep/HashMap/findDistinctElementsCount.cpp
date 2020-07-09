#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;
int count(vector<vector<int> > &a) {
    unordered_set<int> oset;
    unordered_set<int> temp;

    for(int i = 0; i < a[0].size(); i++){
        oset.insert(a[0][i]);
    }

    for(int i = 1; i < a.size(); i++){
        for(int j = 0; j < a[i].size(); j++){
            if(oset.find(a[i][j]) != oset.end()){
                temp.insert(a[i][j]);
            }
        }

        oset = temp;
        temp.clear();
    }

    return oset.size();
}

//Don't make any changes here

int main(int argc,char** argv){

    int n;
    cin>>n;
    vector<vector<int> > v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    cout<<count(v)<<endl;
}