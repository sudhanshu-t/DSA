#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int o = 0, z = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                o++;
            } else {
                z++;
            }
        }

        int moves = min(o, z);
        if (moves & 1) {
            cout << "DA" << endl;
        } else {
            cout << "NET" << endl;
        }
    }
}