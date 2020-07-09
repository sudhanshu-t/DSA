#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a (n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int c = 0, t = 1;
        int i = 0;
        while (i < n) {
            if (c + t >= a[i]) {
                c++;
                t += c;
                c = 0;
                i++;
            } else {
                while (i < n && c + t < a[i]) {
                    i++;
                    c++;
                }
            }
        }

        cout << t << endl;
    }
}