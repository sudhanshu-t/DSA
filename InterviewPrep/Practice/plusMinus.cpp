#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        long long res = s.size();
        long long mn = 0, cur = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+') {
                cur++;
            } else {
                cur--;
            }

            if (cur < mn) {
                res += i + 1;
                mn = cur;
            }
        }
        
        cout << res << endl;
    }
}