#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string b;
        cin >> b;

        string a = "";
        a += b[0];
        
        for (int i = 1; i < b.size() - 1; i += 2) {
            a += b[i];
        }
        
        a += b[b.size() - 1];
        
        cout << a << endl;
    }
}