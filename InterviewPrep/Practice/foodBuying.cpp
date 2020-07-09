#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        long long ans = 0;
        while (n >= 10) {
            long long cur = (n / 10) * 10;
            ans += cur;
            n -= cur;
            n += cur / 10;
        }

        ans += n;

        cout << ans << endl;
    }
    
    return 0;
}