#include <bits/stdc++.h>
using namespace std;

vector<int> solve(list<int>& A) {
    int a = 0;
    int b = 0;
    int moves = 0;
    int a_prev = 0, b_prev = 0;
    while (A.size()) {
        if (A.size())
            moves++;
        while (A.size() && a_prev <= b_prev) {
            a_prev += A.front();
            A.pop_front();
        }
        a += a_prev;
        b_prev = 0;

        if (A.size())    
            moves++;
        while (A.size() && b_prev <= a_prev) {
            b_prev += A.back();
            A.pop_back();
        }
        b += b_prev;
        a_prev = 0;
    }

    vector<int> ans = {moves, a, b};
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        list<int> A;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            A.push_back(x);
        }

        vector<int> ans = solve(A);
        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    }

    return 0;
}