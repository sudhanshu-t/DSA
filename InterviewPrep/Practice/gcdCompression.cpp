#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a (2 * n);
        vector<int> even, odd;
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) {
                even.push_back(i + 1);
            } else {
                odd.push_back(i + 1);
            }
        }

        int c = 0;
        if (even.size() > 1)
            for (int i = 0; i < even.size() - 1; i += 2) {
                cout << even[i] << " " << even[i + 1] << endl;
                c++;

                if (c == n - 1) break;
            }


        if (c == n - 1) continue;

        if (odd.size() > 1)
            for (int i = 0; i < odd.size() - 1; i += 2) {
                cout << odd[i] << " " << odd[i + 1] << endl;
                c++;

                if (c == n - 1) break;
            }

    }

    return 0;
}