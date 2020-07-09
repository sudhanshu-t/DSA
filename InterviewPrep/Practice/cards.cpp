#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> cards;
        for (int i = 1; ; i++) {
            cards.push_back((3 * i * i + i) / 2);
            if (cards[i - 1] > n) {
                break;
            }
        }

        int count = 0;
        for (int i = cards.size() - 2; i >= 0; i--) {
            while (n >= cards[i]) {
                n -= cards[i];
                count++;
            }
        }

        cout << count << endl;
    }
}