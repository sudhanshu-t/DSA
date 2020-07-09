#include <bits/stdc++.h>
using namespace std;

int numDecodings(string s) {
    vector<int> dp (s.size());
    dp[dp.size()-1] = 1;
    for(int i = s.size()-2; i >= 0; i--){
        int c1 = s[i]-'0';
        int c2 = s[i+1]-'0';
        
        int num = c1*10 + c2;
        cout << num << endl;
        if(num <= 26){
            dp[i] = dp[i+1] + ((i+2 < dp.size()) ? dp[i+2] : 1);
        } else {
            dp[i] = dp[i+1];
        }
    }
    
    return dp[0];
}

int main(){
    cout << numDecodings("12") << endl;
}