#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, y, a, b;
        cin >> x >> y >> a >> b;
        long long ans = 0;

        if (x == 0 && y == 0) {
            cout << 0 << endl;
            continue;
        }

        if (x > 0 && y > 0) {
            long long mn = min(x, y);
            long long mx = max(x, y);
            long long d = mx - mn;
            ans += d * a;
            ans += mn * b;
            if (ans > (mx + mn) * a) {
                ans = (mx + mn) * a;
            }
        } else if (x < 0 && y < 0) {
            long long mn = min(x, y);
            long long mx = max(x, y);
            long long d = abs(mx - mn);
            ans += d * a;
            mx = abs(mx);
            ans += mx * b;
            if (ans > (abs(mx) + abs(mn)) * a) {
                ans = (abs(mx) + abs(mn)) * a;
            }
        } else {
            long mn = min(x, y);
            long long mx = max(x, y);
            ans += abs(mx) * a;
            ans += abs(mn) * a;
        }

        cout << ans << endl;
    }
}