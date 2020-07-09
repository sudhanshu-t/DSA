#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<long long> a (n);
        vector<long long> left (n);
        vector<long long> right (n);
        long long pre = 0;
        bool all = true;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pre += a[i];
            left[i] = pre;

            if (a[i] % x != 0) {
                all = false;
            }
        }

        if (all) {
            cout << -1 << endl;
            continue;
        }
        if (pre % x != 0) {
            cout << n << endl;
            continue;
        }

        pre = 0;
        for (int i = n - 1; i >= 0; i--) {
            pre += a[i];
            right[i] = pre;
        }

        int l, r;
        for (int i = 0; i < n; i++) {
            if (a[i] % x != 0) {
                l = i;
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (a[i] % x != 0) {
                r = i;
                break;
            }
        }

        int llen = n - 1 - l;
        int rlen = r;

        if (llen > rlen) {
            cout << llen << endl;
        } else {
            cout << rlen << endl;
        }
    }
}