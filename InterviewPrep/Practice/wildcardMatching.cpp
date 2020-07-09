#include <bits/stdc++.h>
using namespace std;

int dfs(string s, string p, int i, int j, vector<vector<int>>& dp) {
    if (i == s.size() && j == p.size()) {
        return 1;
    }
    
    if (i == s.size()) {
        return 0;
    }
    
    if (j == p.size()) {
        return 0;
    }
    
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    int ans = 0;
    if (p[j] == '*') {
        int o1 = dfs(s, p, i, j + 1, dp);
        if (o1 == 1) {
            dp[i][j] = 1;
            return dp[i][j];
        }
        
        int o2 = dfs(s, p, i + 1, j, dp);
        if (o2 == 1) {
            dp[i][j] = 1;
            return dp[i][j];
        }
        
        int o3 = dfs(s, p, i + 1, j + 1, dp);
        if (o3 == 1) {
            dp[i][j] = 1;
            return dp[i][j];
        }
    } else if (p[j] == '?') {
        ans = dfs(s, p, i + 1, j + 1, dp);
    } else {
        if (s[i] == p[j]) {
            ans = dfs(s, p, i + 1, j + 1, dp);
        } else {
            ans = 0;
        }
    }
    
    dp[i][j] = ans;
    return dp[i][j];
}

bool isMatch(string s, string p) {
    vector<vector<int>> dp (s.size(), vector<int>(p.size(), -1));
    int ans = dfs(s, p, 0, 0, dp);

    

    if (ans == 0) return false;
    return true;
}


int main() {
    string s = "adceb";
    string p = "a*c?b";

    if (isMatch(s, p)) cout << "True" << endl;
    else cout << "False" << endl;
}