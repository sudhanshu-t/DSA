#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> a (2 * n + 1), pre1(2 * n + 1), pre2(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[n + i] = a[i];
    }
    pre1[0] = pre2[0] = a[0] = 0;

    for (int i = 1; i < pre1.size(); i++) {
        pre1[i] = pre1[i - 1] + (a[i] * (a[i] + 1) / 2);
        pre2[i] = pre2[i - 1] + a[i];
    }

    long long res = 0;
    for (int i = 2 * n; i >= n + 1; i--) {
        int l = 1;
        int r = i;
        int ans = i;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (pre2[i] - pre2[mid] < k) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }

        long long extra = pre2[i] - pre2[ans - 1] - k;
        long long sum = pre1[i] - pre1[ans - 1];
        sum -= extra * (extra + 1) / 2;
        res = max(res, sum);
    }

    cout << res << endl;
}