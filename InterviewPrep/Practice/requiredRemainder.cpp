#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, n;
        cin >> x >> y >> n;

        int a = x * (n / x);
        if (a + y <= n) {
            cout << a + y << endl;
        } else if (a - (x - y) >= 0) {
            cout << a - (x - y) << endl;
        }
    }

    return 0;
}