#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;

        if (n % 2 == 0) {
            cout << m * n / 2 << endl;
        } else {
            if (m % 2 == 0) {
                cout << (n - 1) / 2 * m + (m / 2) << endl;
            } else {
                cout << (n - 1) / 2 * m + (m / 2 + 1) << endl;
            }
        }
    }
}