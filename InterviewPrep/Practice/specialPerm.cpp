#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        

        bool done = false;

        if (!done) {
            unordered_set<int> set;
            for (int i = 1; i <= n; i++) {
                set.insert(i);
            }

            int num = 1;
            vector<int> ans;
            ans.push_back(1);
            while (set.size() != 1) {
                if (set.find(num + 2) != set.end()) {
                    ans.push_back(num + 2);
                    set.erase(num);
                    num = num + 2;
                } else if (set.find(num + 3) != set.end()) {
                    ans.push_back(num + 3);
                    set.erase(num);
                    num = num + 3;
                } else if (set.find(num + 4) != set.end()) {
                    ans.push_back(num + 4);
                    set.erase(num);
                    num = num + 4;
                } else if (set.find(num - 2) != set.end()) {
                    ans.push_back(num - 2);
                    set.erase(num);
                    num = num - 2;
                } else if (set.find(num - 3) != set.end()) {
                    ans.push_back(num - 3);
                    set.erase(num);
                    num = num - 3;
                } else if (set.find(num - 4) != set.end()) {
                    ans.push_back(num - 4);
                    set.erase(num);
                    num = num - 4;
                } else {
                    break;
                }
            }

            if (set.size() == 1) {
                for (int i = 0; i < ans.size(); i++) {
                    cout << ans[i] << " ";
                }
                cout << endl;
                done = true;
            }

        }

        if (!done) {
            unordered_set<int> set;
            for (int i = 1; i <= n; i++) {
                set.insert(i);
            }
            int num = 2;
            vector<int> ans;
            ans.push_back(2);
            while (set.size() != 1) {
                if (set.find(num + 2) != set.end()) {
                    ans.push_back(num + 2);
                    set.erase(num);
                    num = num + 2;
                } else if (set.find(num + 3) != set.end()) {
                    ans.push_back(num + 3);
                    set.erase(num);
                    num = num + 3;
                } else if (set.find(num + 4) != set.end()) {
                    ans.push_back(num + 4);
                    set.erase(num);
                    num = num + 4;
                } else if (set.find(num - 2) != set.end()) {
                    ans.push_back(num - 2);
                    set.erase(num);
                    num = num - 2;
                } else if (set.find(num - 3) != set.end()) {
                    ans.push_back(num - 3);
                    set.erase(num);
                    num = num - 3;
                } else if (set.find(num - 4) != set.end()) {
                    ans.push_back(num - 4);
                    set.erase(num);
                    num = num - 4;
                } else {
                    break;
                }
            }

            if (set.size() == 1) {
                for (int i = 0; i < ans.size(); i++) {
                    cout << ans[i] << " ";
                }
                cout << endl;
                done = true;
            }
        }

        if (!done) {
            cout << -1 << endl;
        }
    }

    return 0;
}