#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& arr, int k) {
    int n = arr.size();
    unordered_set<int> set;
    for (int i = 0; i < arr.size(); i++) {
        set.insert(arr[i]);
    }

    if (set.size() > k) {
        return false;
    }

    arr.resize(0);
    for (auto itr : set) {
        arr.push_back(itr);
    }

    sort(arr.begin(), arr.end());

    if (arr.size() > k) {
        return true;
    }

    while (arr.size() < k) {
        arr.push_back(arr[0]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < k; j++) {
            arr.push_back(arr[j]);
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr (n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        bool ans = check(arr, k);
        if (!ans) {
            cout << -1 << endl;
            continue;
        } else {
            cout << arr.size() << endl;
            for (int i = 0; i < arr.size(); i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
}