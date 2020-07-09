#include <bits/stdc++.h>
using namespace std;

class Pair {
public:
    int l;
    int r;
    Pair(int l, int r) {
        this->l = l;
        this->r = r;
    }

    bool operator>(const Pair& o) const {
        if (this->r - this->l == o.r - o.l) {
            return this->l > o.l;
        } else {
            return this->r - this->l < o.r - o.l;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

        int val = 1;

        vector<int> arr (n);
        pq.push(Pair (0, n - 1));
        while (pq.empty() == false) {
            Pair curr = pq.top();
            pq.pop();

            if (curr.l > curr.r) continue;

            int mid = curr.l + (curr.r - curr.l) / 2;
            arr[mid] = val++;

            pq.push(Pair(curr.l, mid - 1));
            pq.push(Pair(mid + 1, curr.r));
        }

        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}