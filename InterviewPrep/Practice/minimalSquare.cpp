#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        if (2 * a == b) {
            int s = 2 * a;
            cout << s * s << endl;
            continue;
        }

        if (2 * b == a) {
            int s = 2 * b;
            cout << s * s << endl;
            continue;
        }
        
        if (a == b) {
            int s = 2 * a;
            cout << s * s << endl;
            continue;
        }
        
        if (a < b) {
            if (2 * a >= b) {
                cout << 4 * a * a << endl;
            } else {
                cout << b * b << endl;
            }
        } else {
            if (2 * b >= a) {
                cout << 4 * b * b << endl;
            } else {
                cout << a * a << endl;
            }
        }
    }

    return 0;
}