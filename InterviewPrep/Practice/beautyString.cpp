#include <bits/stdc++.h>
using namespace std;

string solve(long long n, long long k, map<pair<int, int>, string>& dp) {
    if (k == 1) {
        string ans;
        for (int i = 0; i < n; i++) {
            ans += 'a';
        }
        ans[n - 1] = 'b';
        ans[n - 2] = 'b';
        return ans;
    }
    
    if (n == 3) {
        if (k == 1) {
            return "abb";
        } else if (k == 2) {
            return "bab";
        } else {
            return "bba";
        }
    }

    // if (dp.find(make_pair(n, k)) != dp.end()) {
    //     return dp[{n, k}];
    // }
    
    long long m = (long long) (n * (n - 1)) / 2;
    long long x = (long long) ((n - 1) * (n - 2)) / 2;
    long long y = m - x;

    string ans;
    if (k <= x) {
        ans = 'a' + solve(n - 1, k, dp);
    } else {
        int pos = k - x;
        for (int i = 0; i < n; i++) {
            ans += 'a';
        }

        ans[n - pos] = 'b';
        ans[0] = 'b';
    }

    // dp[{n, k}] = ans;
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        map<pair<int, int>, string> dp;
        cout << solve(n, k, dp) << endl;
    }
}