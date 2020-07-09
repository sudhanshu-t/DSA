#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a (n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] = (a[i] % n + n) % n;
        }

        bool poss = true;
        vector<bool> map (n);
        for (int i = 0; i < n; i++) {
            if (map[(i + a[i]) % n]) {
                poss = false;
                break;
            } else {
                map[(i + a[i]) % n] = true;
            }
        }

        if (poss) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}