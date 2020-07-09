#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>

using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written
// This function takes as input an array of string
// It should return name of winning candidate

vector<string> func(vector<string> &arr) {
    // Write your code here
    unordered_map<string, int> map;
    for(int i = 0; i < arr.size(); i++){
        map[arr[i]]++;
    }

    vector<string> res (1, "");

    priority_queue<string, vector<string>, greater<string>> pq;

    int maxC = 0;
    string pot = "";
    for(auto itr : map){
        if(itr.second > maxC){
            maxC = itr.second;
        }
    }

    for(auto itr : map){
        if(itr.second == maxC){
            pq.push(itr.first);
        }
    }

    string min = pq.top();
    res[0] = min;
    return res;
}

int main(int argc, char** argv){
    int n; cin>>n;
    vector<string> str;
    for (int i = 0; i < n; i++) {
        string s; cin>>s;
        str.push_back(s);
    }
    vector<string> res = func(str);
    cout<<res[0];
}