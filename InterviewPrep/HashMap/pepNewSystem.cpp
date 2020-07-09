#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;
// --------------------------------------------------------------
// This is a functional problem. You have to complete this function.
// It takes as input a string array.
// It should print "Verified" if the username doesn't exists already, 
//else should print the username with a number added to the end of the username.

void solve(vector<string> &str) {
    // write your code here.
    unordered_set<string> map;
    vector<string> ans (str.size());
    unordered_set<int> num;

    for(int i = 1; i < 9; i++){
        num.insert(i);
    }

    for(int i = 0; i < str.size(); i++){
        if(map.find(str[i]) == map.end()){
            map.insert(str[i]);
            ans[i] = "Verified";
        } else {
            string s;
            str[i] = str[i] + to_string(1);                    

            while(map.find(str[i]) != map.end()){
                char ch = str[i][str[i].size() - 1];
                str[i] = str[i].substr(0, str[i].size() - 1) + to_string((ch - '0') + 1);                    
            }

            map.insert(str[i]);
            ans[i] = str[i];
        }
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}

int main(int argc,char** argv){
    // Length of the array
    int N ;
    cin>>N;
    vector<string> arr(N);
    for (int i = 0; i < N; i++) {
        cin>>arr[i];
    }
    
    solve(arr);
}