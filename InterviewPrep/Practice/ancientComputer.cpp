#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b, vector<bool>& dp) {
    if (a == b) return 0;

    if (dp[a] != -1) return dp[a];

    int o1 = solve(2 * a, b, dp);
    int o2 = solve(4 * a, b, dp);
    int o3 = solve(8 * a, b, dp);
    int o4 = INT_MAX, o5 = INT_MAX, o6 = INT_MAX;
    if (a % 2 == 0) {
        o4 = solve(a / 2, b, dp);
    }
    if (a % 4 == 0) {
        o5 = solve(a / 4, b, dp);
    }
    if (a % 8 == 0) {
        o6 = solve(a / 8, b, dp);
    }

    dp[a] = min(o1, min(o2, min(o3, min(o4, min(o5, o6)))));
    return dp[a];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        vector<bool> dp(100000000, -1);
        cout << solve(a, b, dp) << endl;
    }
}