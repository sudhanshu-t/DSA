#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        int ans = INT_MAX;

        // for (int i: a) cout << i << " ";
        // cout << endl;

        for (int i = 0; i < n - 1; i++) {
            ans = min(ans, abs(a[i] - a[i + 1]));
        }

        cout << ans << endl;
    }
}