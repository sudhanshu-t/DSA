#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        priority_queue<int> a;
        priority_queue<int> b;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push(x);
        }

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            b.push(x);
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (a.top() >= b.top()) {
                sum += a.top();
                a.pop();
            } else {
                if (k) {
                    sum += b.top();
                    b.pop();
                    k--;
                } else {
                    sum += a.top();
                    a.pop();
                }
            }
        }

        cout << sum << endl;
    }
}