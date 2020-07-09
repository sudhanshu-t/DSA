#include <bits/stdc++.h>
using namespace std;

int main() {
       int n;
       cin >> n;
       int x = 0, y = 0;
       cout << (n + 1) * 3 + 1 << endl;     
       for (int i = 0; i < n + 1; i++) {
              cout << x << " " << y << endl;
              cout << x + 1 << " " << y << endl;
              cout << x << " " << y + 1 << endl;
              x++;
              y++;
       }
       cout << x << " " << y << endl;

       return 0;
}