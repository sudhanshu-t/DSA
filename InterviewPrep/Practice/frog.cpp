#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int first = INT_MAX, last = -1;
        int between = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'R') {
                first = min(first, i + 1);
                last = max(last, i + 1);
            }
        }

        int lr = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'R') {
                if (lr != -1) {
                    between = max(between, i - lr);
                }
                lr = i;
            }
        }
        
        if (first == INT_MAX || last == INT_MIN) {
            cout << s.size() + 1 << endl;
        } else {
            last = s.size() - last + 1;
            if (between == 0)
                cout << max(first, last) << endl;
            else
                cout << max(between, max(first, last)) << endl;
        }
    }
}