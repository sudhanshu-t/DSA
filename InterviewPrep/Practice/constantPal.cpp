#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int ans = INT_MAX;
        vector<int> mxvl, mnvl;
        unordered_map<int, int> sum;
        for (int i = 0; i < n / 2; i++) {
            int mn = min(arr[i], arr[n - i - 1]);
            int mx = max(arr[i], arr[n - i - 1]);

            mxvl.push_back(mx);
            mnvl.push_back(mn);

            sum[mn + mx]++;
        }

        sort(mxvl.begin(), mxvl.end());
        sort(mnvl.begin(), mnvl.end());

        for (int x = 2; x <= 2 * k; x++) {
            int mn_less_than_x = lower_bound(mnvl.begin(), mnvl.end(), x) - mnvl.begin();
            int mn_greater_than_x_minus_1 = n / 2 - mn_less_than_x;
            int mx_less_than_x_minus_k = lower_bound(mxvl.begin(), mxvl.end(), x - k) - mxvl.begin();

            int c0 = sum[x];
            int c2 = mn_greater_than_x_minus_1 + mx_less_than_x_minus_k;
            int c1 = n / 2 - c0 - c2;

            ans = min(ans, c1 + 2 * c2);
        }

        cout << ans << endl;
    }
}