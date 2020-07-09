#include <bits/stdc++.h>
using namespace std;

bool isOneEditDistance(string s, string t) {
    if(s == t){
        return true;
    }
    vector<vector<int>> dp (t.size()+1, vector<int> (s.size()+1));
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
            if(i == 0){
                dp[i][j] = j;
                continue;
            }
            
            if(j == 0){
                dp[i][j] = i;
                continue;
            }
                            
            if(t[i-1] == s[j-1]){
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
            }
            
            if(i == j && dp[i][j] == 1){
                // cout << s.substr(j) << endl;
                // cout << t.substr(i) << endl;
                if(s.substr(j) == t.substr(i)){
                    continue;
                } else if(s.substr(j-1) == t.substr(i) || s.substr(j) == t.substr(i-1)) {
                    return true;
                } else {
                    return false;
                }
            } else if(i == j && dp[i][j] == 0){
                // cout << s.substr(j) << endl;
                // cout << t.substr(i) << endl;
                if(s.substr(j) == t.substr(i)){
                    return true;
                }
            }
        }
    }
    
    return ((dp[dp.size()-1][dp[0].size()-1] == 1) ? true : false);
}

int main(){
    cout << isOneEditDistance("ab", "acb") << endl;
}