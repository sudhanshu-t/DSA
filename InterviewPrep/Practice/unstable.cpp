#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        if (n == 1) {
            cout << 0 << endl;
            continue;
        }

        if (n == 2) {
            cout << m << endl;
            continue;
        }

        cout << 2 * m << endl;

        // if (n == m) {
        //     cout << 2 * m << endl;
        //     continue;
        // }


        // int total = n / 2;
        // int remc = 1;
        // int maxc = total - remc;

        // if (maxc == 1) {

        // }

        // int max = m / maxc;
        // int ans = 0;
        // ans += 2 * maxc * max;
        // int rem = m - ans;
        // ans += 2 * rem;

        // cout << ans << endl;
    }
}