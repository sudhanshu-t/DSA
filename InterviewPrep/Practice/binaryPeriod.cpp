#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string T;
        cin >> T;
        char fc = T[0];
        string S;
        S += fc;

        bool allSame = true;

        for (int i = 0; i < T.size(); i++) {
            if (T[i] != fc) {
                allSame = false;
                break;
            }
        }

        if (allSame) {
            S = T;
            cout << S << endl;
            continue;
        }
        
        for (int i = 1; i < T.size(); i++) {
            if (T[i] == fc) {
                char oc;
                if (fc == '0') oc = '1';
                else oc = '0';
                S += oc;
                S += fc;
                fc = S[S.size() - 1];
            } else {
                S += T[i];
                fc = S[S.size() - 1];
            }
        }

        cout << S << endl;
    }
}