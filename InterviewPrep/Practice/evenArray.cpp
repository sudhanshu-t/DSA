#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a (n);

        int e = 0, o = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) e++;
            else o++;
        }

        if (n % 2 != 0) {
            if (e != n / 2 + 1) {
                cout << -1 << endl;
                continue;
            }
        } else {
            if (e != o) {
                cout << -1 << endl;
                continue;
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 != i % 2) {
                for (int j = i + 1; j < n; j += 2) {
                    if (a[j] % 2 != j % 2) {
                        swap(a[i], a[j]);
                        count++;
                        break;
                    }
                }
            }
        }

        cout << count << endl;
    }
}