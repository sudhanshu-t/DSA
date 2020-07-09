#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> a (n);
        map<long long, long long> map;
        long long mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            if (a[i] % k == 0) {
                continue;
            }

            map[k - a[i] % k]++;
            mx = max(mx, map[k - a[i] % k]);
        }

        long long ans = 0;
        for (auto itr: map) {
            if (itr.second == mx) {
                ans = k * (itr.second - 1) + itr.first + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}