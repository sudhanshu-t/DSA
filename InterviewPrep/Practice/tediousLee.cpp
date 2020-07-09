#include <bits/stdc++.h>
using namespace std;

int M = 1e9 + 7;
int mn = 2e6 + 7;
vector<int> dp (mn);

int main() {
    dp[0] = dp[1] = 0;
    dp[2] = 4;

    for (int i = 3; i < mn; i++) {
        int a = dp[i - 1] % M;
        int b = 2 * dp[i - 2] % M;
        dp[i] = a + b + ((i + 1) % 3 == 0 ? 4 : 0);
        dp[i] %= M;
    }
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        cout << dp[n - 1] % M << endl;
    }

    return 0;
}