#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> st (n, 1);
    vector<long long> end (n, 1);

    long long ans = INT_MIN;

    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            end[i] = end[i - 1] + 1;
        }

        ans = max(ans, end[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) {
            st[i] = st[i + 1] + 1;
        }
        
        ans = max(ans, st[i]);
    }

    // for (auto i: st) cout << i << " ";
    // cout << endl;
    // for (auto i: end) cout << i << " ";
    // cout << endl;

    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] < a[i + 1]) {
            ans = max(ans, end[i - 1] + st[i + 1]);
        }
    }

    cout << ans << endl;

    return 0;
}