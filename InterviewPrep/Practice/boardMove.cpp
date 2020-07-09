#include <bits/stdc++.h>

using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        unsigned long long sum = 0;
        unsigned long long m1 = 1;
        unsigned long long m2 = 8;
        for (int i = 0; i < n / 2; i++) {
            sum += m1 * m2;
            m1++;
            m2 += 8;
            // cout << sum << endl;
        }

        cout << sum << endl;
    }

    return 0;
}