#include <bits/stdc++.h>
using namespace std;

// INCORRECT ALGORITHM

void solve(vector<int>& a, vector<int>& b, int k) {
    vector<int> can (b.size());
    int n1 = a.size();

    while (k--) {
        int minv = INT_MAX;
        int mini = -1;

        for (int i = 0; i < b.size(); i++) {
            if (can[i] < n1 && b[i] + a[can[i]] < minv) {
                minv = b[i] + a[can[i]];
                mini = i;
            }
        }

        cout << a[can[mini]] << ", " << b[mini] << endl;
        can[mini]++;
    }
}

int main() {
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {0,1,1,1,2,3,3};

    solve(a, b, 35);
}