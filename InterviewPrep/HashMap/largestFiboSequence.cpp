#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include <unordered_set>

using namespace std;
void solve(vector<int> &v) {
    // Generating fibo sequence till 1000
    unordered_set<int> set;
    priority_queue<int> pq;

    set.insert(0);
    set.insert(1);
    
    pq.push(0);
    pq.push(1);

    while(pq.top() < 1000){
        int one = pq.top(); pq.pop();
        int two = pq.top(); pq.pop();

        pq.push(one + two);
        pq.push(one);
        pq.push(two);
        set.insert(one + two);
    }

    for(int i = 0; i < v.size(); i++){
        if(set.find(v[i]) != set.end()){
            cout << v[i] << " ";
        }
    }
}
    
int main(int argc,char** argv){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    solve(v);
}