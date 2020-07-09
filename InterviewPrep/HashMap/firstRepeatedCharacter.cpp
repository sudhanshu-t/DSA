#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input the String s. It should return the first repeated
// character if present, else should return $.
char solve(string& s) {
    // write your code here.
    unordered_map<char, int> map;

    for(int i = 0; i < s.size(); i++){
        map[s[i]]++;

        if(map[s[i]] == 2){
            return s[i];
        }
    }

    // cout << map.size() << endl;

    // for(auto itr : map){
    //     cout << itr.first << " " << itr.second << endl;
    // }

    return '$';
}

int main(int argc,char** argv) {

    string str;
    cin>>str;
    cout<<solve(str)<<endl;

}