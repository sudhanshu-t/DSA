#include <bits/stdc++.h>
using namespace std;

vector<int> dp (1000000, -1);

int solve(int n) {
    if (n == 1) {
        return 0;
    }

    if (dp[n] != -1) return dp[n];
    
    int o1, o2;
    if (n % 6 == 0) {
        int a = solve(n / 6);
        if (a == -1) {
            return dp[n];
        }

        o1 = 1 + a;
    } else {
        int b = solve(2 * n);;
        if (b == -1) return dp[n];
        o2 = 1 + b;
    }

    dp[n] = min(o1, o2);
    return dp[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        int moves = 0;
        while (true) {
            if (n == 1) {
                break;
            }
            
            if (n % 6 == 0) {
                n = n / 6;
                moves++;
            } else if (n % 3 == 0) {
                n = 2 * n;
                moves++;
            } else {
                moves = -1;
                break;
            }
        }
        
        cout << moves << endl;
    }

    return 0;
}