#include <bits/stdc++.h>
using namespace std;

int mergeStones(vector<int>& stones, int k) {
    int n = stones.size();
    while(n != k){
        n -= k-1;
        
        if(n < k){
            return -1;
        }
    }
    
    vector<int> leftSum (stones.size());
    for(int i = k-1; i < leftSum.size(); i++){
        for(int j = i-k+1; j <= i; j++){
            leftSum[i] += stones[j];
        }
    }

    for(int i = 0; i < leftSum.size(); i++){
        cout << leftSum[i] << " ";
    }
    cout << endl;

    vector<vector<int>> dp (stones.size(), vector<int> (stones.size(), 0));
    
    for(int x = k-1; x < dp[0].size(); x++){
        for(int i = 0, j = x; j < dp[0].size(); i++, j++){
            if(x == k-1){
                dp[i][j] = leftSum[j];
                continue;
            }
            
            int myMin = INT_MAX;
            for(int v = 0; v < k; v++){
                int lSum = 0, rSum = 0;
                
                for(int w = i; w < i+v; w++){
                    lSum += stones[w];
                }
                
                for(int w = j-k+1+v+1; w <= j; w++){
                    rSum += stones[w];
                }
                
                myMin = min(myMin, 2*dp[i+v][j-k+1+v] + lSum + rSum);

                if(i == 0 && j == 6){
                    cout << lSum << " " << rSum << " " << dp[i+v][j-k+1+v] << endl;
                }
            }
            
            dp[i][j] = myMin;
        }
    }

    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    return dp[0][dp.size() - 1];
}
    int mergeStones2(vector<int>& stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1)) return -1;

        vector<int> prefix(n + 1);
        for (int i = 0; i <  n; i++)
            prefix[i + 1] = prefix[i] + stones[i];

        vector<vector<int> > dp(n, vector<int>(n));
        for (int m = K; m <= n; ++m)
            for (int i = 0; i + m <= n; ++i) {
                int j = i + m - 1;
                dp[i][j] = INT_MAX;
                for (int mid = i; mid < j; mid += K - 1)
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
                if ((j - i) % (K - 1) == 0)
                    dp[i][j] += prefix[j + 1] - prefix[i];
            }
            for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
        return dp[0][n - 1];
    }
int main(){
    vector<int> stones = {3,2,4,1,5,7,3};
    cout << mergeStones2(stones, 3) << endl;
}