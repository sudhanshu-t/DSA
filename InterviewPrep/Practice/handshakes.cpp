#include <bits/stdc++.h>
using namespace std;

long long M = 1000000007;

long long solve(int n, vector<long long>& memo){
    if(n == 0 || n == 2){
        memo[n] = 1;
        return 1;
    }
    
    if(memo[n] != -1){
        return memo[n];
    }
    
    long long ans = 0;
    for(int i = 0; i < n-1; i+=2){
        long long a = solve(i, memo);
        long long b = solve(n-i-2, memo);
        ans += ((a%M)*(b%M))%M;
    }
    
    memo[n] = ans%M;
    return memo[n];
}

int numberOfWays(int num_people) {
    vector<long long> memo (num_people+1, -1);
    long long ans = solve(num_people, memo);
    return ans;
}

int main(){
    cout << "Number of ways are " << numberOfWays(1000) << endl;
}