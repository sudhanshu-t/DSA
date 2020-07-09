#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string x;
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            x += c;
        }

        string a;
        string b;

        a.resize(n);
        b.resize(n);

        if (x[0] == '1') {
            a[0] = '2';
            b[0] = '2';
        } else {
            a[0] = '1';
            b[0] = '1';
        }

        for (int i = 1; i < n; i++) {
            if (x[i] == '0') {
                a[i] = '0';
                b[i] = '0';
            } else if (x[i] == '1') {
                if (a > b) {
                    a[i] = '0';
                    b[i] = '1';
                } else {
                    a[i] = '1';
                    b[i] = '0';
                }
            } else {
                if (a == b) {
                    a[i] = '1';
                    b[i] = '1';
                } else if (a > b) {
                    a[i] = '0';
                    b[i] = '2';
                } else {
                    a[i] = '2';
                    b[i] = '1';
                }
            }
        }

        cout << a << endl << b << endl;
    }
}