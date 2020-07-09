#include <bits/stdc++.h>
using namespace std;

int solve(string a, int k, vector<int>& ones) {
    int ans = 0;
    for (int i = 0; i < ones.size() - 1; i++) {
        int l = ones[i] + k + 1;
        int r = ones[i + 1] - k - 1;

        if (l > r) continue;

        int n = r - l + 1;
        ans += n / (k + 1);
        if (n % (k + 1) != 0) {
            ans++;
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        string a;
        cin >> a;

        int num = 0;
        int first = INT_MAX;
        int last = INT_MIN;
        vector<int> ones;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '1') {
                num++;
                first = min(first, i);
                last = max(last, i);
                ones.push_back(i);
            }
        }

        int ans;
        if (num == 0) {
            ans = n / (k + 1);
            if (n % (k + 1) != 0) ans++;
            
            cout << ans << endl;
            continue;
        }
        
        ans = solve(a, k, ones);

        for (int i = first - k - 1; i >= 0; i -= k + 1) {
            ans++;
        }

        for (int i = last + k + 1; i < n; i += k + 1) {
            ans++;
        }
        
        cout << ans << endl;
    }
}