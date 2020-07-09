#include<iostream>
#include<vector>
#include<string>
#include<limits.h>

using namespace std;
// This is a functional problem. You have to complete this function.
// It takes as input a string representing a time.
// It should return the next closest time.

vector<int> v;

int ceil(int k){
    int c = INT_MAX;
    for(int i = 0; i < v.size(); i++){
        if(v[i] > k && c > v[i]){
            c = v[i];
        }
    }

    if(c == INT_MAX){
        return -1;
    }

    return c;
}

bool isValid(int n, int p){
    if(n == -1){
        return false;
    }

    if(p == 0 && n > 2){
        return false;
    }

    if(p == 1 && v[0] == 2 && n > 4){
        return false;
    }

    if(p == 2 && n > 5){
        return false;
    }

    return true;
}

string nextClosestTime(string& t) {
    // write your code here. 
    v.push_back(t[0] - '0');
    v.push_back(t[1] - '0');
    v.push_back(t[3] - '0');
    v.push_back(t[4] - '0');

    // cout << ceil(4) << endl; 

    int minv = min(v[0], min(v[1], min(v[2], v[3])));

    if(isValid(ceil(v[3]), 3)){
        t[4] = to_string(ceil(v[3]))[0];
        return t;
    } else {
        t[4] = to_string(minv)[0];
    } 
    
    if(isValid(ceil(v[2]), 2)){
        t[3] = to_string(ceil(v[2]))[0];
        return t;
    } else {
        t[3] = to_string(minv)[0];
    }
    
    if(isValid(ceil(v[1]), 1)){
        t[1] = to_string(ceil(v[1]))[0];
        return t;
    } else {
        t[1] = to_string(minv)[0];
    }
    
    if(isValid(ceil(v[0]), 0)){
        t[0] = to_string(ceil(v[0]))[0];
        return t;
    } else {
        t[0] = to_string(minv)[0];
    }

    return t;
}

int main(int argc,char** argv){
    string time;
    cin>>time;
    cout<<nextClosestTime(time)<<endl;

}