#include <bits/stdc++.h>
using namespace std;

unsigned long long solve(long long si, long long sj, long long di, long long dj) {
    return ((di - si) * (dj - sj)) + 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;

        cout << solve(sx, sy, dx, dy) << endl;
    }
}