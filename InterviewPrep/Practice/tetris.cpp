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

        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            if ((a[i + 1] - a[i]) % 2 != 0) ok = false;
        }

        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}