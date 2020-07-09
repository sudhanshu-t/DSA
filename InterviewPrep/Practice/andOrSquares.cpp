#include <bits/stdc++.h>
using namespace std;

int main() {
       int n;
       cin >> n;
       vector<int> a (n);
       for (int i = 0; i < n; i++) {
              cin >> a[i];
       }

       vector<long long> b (n);
       for (int i = 0; i < 20; i++) {
              int count = 0;
              int bm = 1 << i;
              for (int j = 0; j < n; j++) {
                     if ((a[j] & bm) != 0) {
                            count++;
                     }
              }

              for (int j = 0; j < count; j++) {
                     b[n - j - 1] = (b[n - j - 1] | bm);
              }
       }

       long long sum = 0;
       for (int i = 0; i < n; i++) {
              sum += b[i] * b[i];
       }

       cout << sum << endl;

       return 0;
}