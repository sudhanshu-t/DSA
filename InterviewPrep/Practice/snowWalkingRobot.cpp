#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int l = 0, r = 0, u = 0, d = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') l++;
            else if (s[i] == 'R') r++;
            else if (s[i] == 'U') u++;
            else d++;
        }

        string ans;
        int h = min(l, r);
        int v = min(u, d);

        if (h == 0) {
            v = min(v, 1);
        } else if (v == 0) {
            h = min(h, 1);
        }

        for (int i = 0; i < v; i++) {
            ans += 'U';
        }

        for (int i = 0; i < h; i++) {
            ans += 'R';
        }

        for (int i = 0; i < v; i++) {
            ans += 'D';
        }

        for (int i = 0; i < h; i++) {
            ans += 'L';
        }

        cout << ans.size() << endl;
        cout << ans << endl;
    }

    return 0;
}