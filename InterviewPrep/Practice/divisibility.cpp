#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        if (a % b == 0) {
            cout << 0 << endl;
        } else if (a > b) {
            int rem = a % b;
            cout << b - rem << endl;
        } else {
            cout << b - a << endl;
        }
    }
    
    return 0;
}