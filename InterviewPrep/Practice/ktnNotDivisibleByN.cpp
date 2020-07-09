#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        if (k < n) {
            cout << k << endl;
            continue;
        }

        if (k == n) {
            cout << k + 1 << endl;
            continue;
        }

        int div;
        // if (k % n != 0)
        //     div = k / (n - 1);
        // else
            div = (k - 1) / (n - 1);
        
        int already = div * (n - 1);
        int lastDiv = div * n;
        cout << lastDiv + k - already << endl;
    }

    return 0;
}