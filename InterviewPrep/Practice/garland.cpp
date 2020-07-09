#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> pre (n), dp (n);
        pre[0] = s[0] - '0';
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + (s[i] - '0');
        }

        for (int i = dp.size() - 1; i >= 0; i--) {
            int o1 = (s[i] - '0') ^ 1;
            if (i + k - 1 < n) {
                o1 += pre[i + k - 1] - pre[i];
            } else {
                o1 += pre[n - 1] - pre[i];
            }

            if (i + k < n) o1 += dp[i + k];

            int o2 = pre[n - 1] - pre[i] + (s[i] - '0');

            dp[i] = min(o1, o2);
        }

        int ans = n;

        for (int i = 0; i < pre.size(); i++) {
            dp[i] = ((i - 1 >= 0) ? pre[i - 1] : 0) + dp[i];
            ans = min(ans, dp[i]);
        }

        cout << ans << endl;
    }
}