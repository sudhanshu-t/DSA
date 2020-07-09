#include<iostream>
#include<vector>
#include <unordered_set>

using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
int open_closeTabs(vector<string> T) {
    unordered_set<int> set;

    for(int i = 0; i < T.size(); i++){
        if(T[i][0] == 'E'){
            set.clear();
        } else {
            if(set.find(T[i][0] - '0') == set.end()){
                set.insert(T[i][0] - '0');
            } else {
                set.erase(T[i][0] - '0');
            }
        }
    }

    return set.size();
}

//Dont make changes here
int main(int argc, char** argv){
    int n;
    cin>>n;
    vector<string> T;
    for (int i = 0; i < n; i++) {
        string s;
        cin>>s;
        T.push_back(s);
    }
    cout<<open_closeTabs(T);
}