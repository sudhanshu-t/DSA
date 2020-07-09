#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> res;
        int power = 1;
        while (n) {
            int d = n % 10;
            n = n / 10;
            int val = power * d;
            power *= 10;
            if (d == 0) continue;
            res.push_back(val);
        }

        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }

    return 0;
}