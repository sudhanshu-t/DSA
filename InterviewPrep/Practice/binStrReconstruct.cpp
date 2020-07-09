#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        string ans;

        if (n1 == 0) {
            if (n0 == 0) {
                for (int i = 0; i <= n2; i++) {
                    ans += '1';
                }
                cout << ans << endl;
            }

            if (n2 == 0) {
                for (int i = 0; i <= n0; i++) {
                    ans += '0';
                }
                cout << ans << endl;
            }

            continue;
        }
        
        for (int i = 0; i <= n0; i++) {
            ans += '0';
        }

        for (int i = 0; i <= n2; i++) {
            ans += '1';
        }

        n1--;
        if (n1 == 0) {
            cout << ans << endl;
            continue;
        }

        while (n1 > 1) {
            n1 -= 2;
            ans += "01";
        }

        if (n1 == 0) {
            cout << ans << endl;
            continue;
        }

        ans += '0';
        cout << ans << endl;
    }

    return 0;
}