#include <bits/stdc++.h>
using namespace std;

int in(int x, int l, int r) {
    return l <= x && x <= r;
}

int solve(vector<int>& a, int i, int j, int h, int l, int r, vector<vector<int>>& dp) {
    if (i == a.size() - 1) {
        return max(in((j + a[i]) % h, l, r), in((j + a[i] - 1) % h, l, r));
    }

    if (dp[i][j % h] != -1) return dp[i][j % h];
    
    dp[i][j % h] = max(solve(a, i + 1, j + a[i], h, l, r, dp) + in((j + a[i]) % h, l, r),
                       solve(a, i + 1, j + a[i] - 1, h, l, r, dp) + in((j + a[i] - 1) % h, l, r));

    return dp[i][j % h];
}

int main() {
    int n, h, l, r;
    cin >> n >> h >> l >> r;

    vector<int> a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp (n + 1, vector<int> (h, -1));
    cout << solve(a, 0, 0, h, l, r, dp) << endl;
}