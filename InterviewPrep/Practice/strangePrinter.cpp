#include <bits/stdc++.h>
using namespace std;

int solve(string s, int l, int r, vector<vector<int>>& dp) {
    // cout << s.substr(l, r - l + 1) << endl;
    if (l > r) {
        return 0;
    }
    
    if (l == r) {
        return 1;
    }
    
    if (dp[l][r] != 0) {
        return dp[l][r];
    }
    
    int sum = 0;
    int os = l;
    int i = os;
    while (i < s.size()) {
        int is, ie;
        while (i <= r && s[i] == s[os]) {
            i++;
        }

        if (i > r) {
            break;
        }

        is = i;
        while (i <= r && s[i] != s[os]) {
            i++;
        }

        if (i > r) {
            cout << s.substr(is, r - is + 1) << endl;
            sum += solve(s, is, r, dp);
            break;
        }

        ie = i - 1;
        cout << s.substr(is, ie - is + 1) << endl;
        sum += solve(s, is, ie, dp);
    }
    
    dp[l][r] = 1 + sum;
    return dp[l][r];
}

int strangePrinter(string s) {
    vector<vector<int>> dp (100, vector<int>(100));
    return solve(s, 0, s.size() - 1, dp);
}

int main() {
    cout << strangePrinter("sudhanshutiwari") << endl;
}