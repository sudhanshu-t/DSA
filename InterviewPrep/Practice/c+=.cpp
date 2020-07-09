#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b, n;
        cin >> a >> b >> n;

        long long acpy = a;
        long long bcpy = b;
        a = min(acpy, bcpy);
        b = max(acpy, bcpy);

        int count = 0;
        while (true) {
            a += b;
            count++;

            if (a > n) {
                cout << count << endl;
                break;
            }

            long long t = a;
            a = b;
            b = t;
        }
    }
}