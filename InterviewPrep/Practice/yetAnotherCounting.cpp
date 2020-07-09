#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int a, b;
vector<int> ps;

long long getAns(long long x) {
    return 1LL * (ps[a * b - 1] * (x / (a * b))) + ps[x % (a * b)];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        LL q;
        cin >> a >> b >> q;
        ps.resize(a * b, 0);
        for (int i = 0; i < a * b; i++) {
            if (i == 0) {
                ps[i] = 0;
                continue;
            }
            int va = ((i % a) % b);
            int vb = ((i % b) % a);
            ps[i] = ps[i - 1];
            if (va != vb) {
                ps[i]++;
            }
        }
        for (int i = 0; i < q; i++) {
            LL l, r;
            cin >> l >> r;
            if(a == b)
                cout << 0 << " ";
            else
                cout << getAns(r) - getAns(l - 1) << " ";
        }
        cout << endl;
    }
    return 0;
}