#include <bits/stdc++.h>
using namespace std;

int maximumMinimumPath(vector<vector<int>>& A) {
    priority_queue<tuple<int, int, int>> pq;
    pq.push(A[0][0], 0, 0);
    int ans = INT_MIN;
    while (!pq.empty()) {
        tuple<int, int, int> cur = pq.top(); pq.pop();
        
    }
}

int main() {
    
}