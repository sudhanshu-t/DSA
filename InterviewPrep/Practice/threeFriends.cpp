#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        long long ans = INT_MAX;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                for (int k = -1; k <= 1; k++) {
                    long long na = a + i;
                    long long nb = b + j;
                    long long nc = c + k;
                    long long A = abs(na - nb);
                    long long B = abs(nb - nc);
                    long long C = abs(na - nc);
                    ans = min(ans, A + B + C);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}