#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        stack<char> st;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else {
                if (st.size() > 0 && st.top() == '(') {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }

        cout << st.size() / 2 << endl;
    }
}