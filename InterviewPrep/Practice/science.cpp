#include <bits/stdc++.h>
using namespace std;

typedef std::pair<int,int> Pair;

vector<int> check(vector<double>& bac, vector<int>& psf, vector<int>& ans, double n, double sum, map<Pair, vector<int>>& dp) {
    if (sum > n) {
        vector<int> temp (1000000);
        return temp;
    }
    
    if (sum == n) {
        dp[make_pair(sum, bac.size())] = psf;
        if (ans.size() > psf.size()) {
            ans = psf;
        }
        return psf;
    }

    if (dp.find(make_pair(sum, bac.size())) != dp.end()) {
        return dp[make_pair(sum, bac.size())];
    }

    for (int i = bac.size(); i >= 0; i--) {
        vector<double> temp;
        for (int j = i - 1; j >= 0; j--) {
            temp.push_back((bac[j] * 1.0) / 2);
            temp.push_back((bac[j] * 1.0) / 2);
        }

        for (int j = i; j < bac.size(); j++) {
            temp.push_back(bac[j]);
        }

        double new_sum = 0;
        for (int j = 0; j < temp.size(); j++) {
            temp[j]++;
            new_sum += temp[j];
            // cout << temp[j] << " ";
        }
        // cout << endl << new_sum << endl;

        psf.push_back(i);
        vector<int> rres = check(temp, psf, ans, n, new_sum, dp);
        psf.pop_back();
    }

    dp[make_pair(sum, bac.size())] = ans;
    return ans;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        vector<int> ans;
        int sum = 0;
        for (int i = 1; sum + i <= n; i *= 2) {
            ans.push_back(i);
            sum += i;
        }

        if (sum < n) {
            ans.push_back(n - sum);
            sort(ans.begin(), ans.end());
        }

        cout << ans.size() - 1 << endl;
        for (int i = 0; i < ans.size() - 1; i++) {
            cout << ans[i + 1] - ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}