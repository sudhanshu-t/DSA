#include <bits/stdc++.h>
using namespace std;

double nthRoot(int A, int N) 
{ 
    // intially guessing a random number between 
    // 0 and 9 
    double xPre = rand() % 10; 
  
    //  smaller eps, denotes more accuracy 
    double eps = 1e-3; 
  
    // initializing difference between two 
    // roots by INT_MAX 
    double delX = INT_MAX; 
  
    //  xK denotes current value of x 
    double xK; 
  
    //  loop untill we reach desired accuracy 
    while (delX > eps) 
    { 
        //  calculating current value from previous 
        // value by newton's method 
        xK = ((N - 1.0) * xPre + 
              (double)A/pow(xPre, N-1)) / (double)N; 
        delX = abs(xK - xPre); 
        xPre = xK; 
    } 
  
    return xK; 
} 

pair<long long, vector<int>> solve(vector<int>& a, long long k, long long psf, int idx) {
    if (idx == 9) {
        for (int i = 1; i <= 100; i++) {
            if (psf * i >= k) {

            }
        }
    }
    
    int minsum;
    vector<int> ans;
    for (int i = 1; i <= 100; i++) {
        a[idx] = i;
        pair<long long, vector<int>> rres = solve(a, k, i * psf, idx + 1);
        if (rres.first < minsum) {
            minsum = rres.first;
            ans = rres.second;
            ans.insert(ans.begin(), i);
        }
    }

    return make_pair(minsum, ans);
}

int main() {
    long long k;
    cin >> k;
    string s = "codeforces";

    vector<int> a = solve(k, 1, 0);
}