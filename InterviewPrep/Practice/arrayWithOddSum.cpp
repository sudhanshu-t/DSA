#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a (n);
        int e = 0, o = 0, s = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) e++;
            else o++;

            s += a[i];
        }

        if (s % 2 != 0) {
            cout << "YES" << endl;
            continue;
        }

        if (o == 0) {
            cout << "NO" << endl;
            continue;
        }

        if (e == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}