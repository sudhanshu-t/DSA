#include <bits/stdc++.h>
using namespace std;

long long sum(int n) {
    return 2 * (pow(2, n) - 1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long a = 0, b = 0;

        int half = n / 2;
        int power = 1;
        for (int i = 0; i < half - 1; i++) {
            int val = (1 << power);
            power++;
            a += val;
        }

        a += pow(2, n);
        long long totalSum = sum(n);
        b = totalSum - a;

        long long ans = abs(a - b);
        cout << ans << endl;
    }
}