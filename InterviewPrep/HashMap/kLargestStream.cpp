#include<iostream>
#include<string>
#include<vector>
#include <queue>

using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.

void subarraysDivByK(vector<int> A, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans (A.size());

    for(int i = 0; i < K-1; i++){
        ans[i] = -1;
        pq.push(A[i]);
    }

    pq.push(A[K-1]);
    ans[K-1] = pq.top();

    for(int i = K; i < A.size(); i++){
        if(A[i] < pq.top()){
            ans[i] = pq.top();
        } else {
            pq.push(A[i]);
            pq.pop();
            ans[i] = pq.top();
        }
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return;
}


int main(int argc,char** argv){

    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    subarraysDivByK(v,k);
}