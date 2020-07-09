#include<iostream>
#include<vector>
#include<string>
#include <queue>
#include <stack>

using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array,n length of array and k.
// It should print required output.
void solve(int n,vector<int>& arr,int k){
    //Write your code here
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }

    for(int i = k; i < arr.size(); i++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        } else {
            continue;
        }
    }

    stack<int> st;

    while(pq.size() != 0){
        st.push(pq.top());    
        pq.pop();
    }

    while(st.size() != 0){
        cout << st.top() << " "; st.pop();
    }

    cout << endl;
}

int main(int argc,char** argv){
    int n;
    cin>>n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    int k;
    cin>>k;
    solve(n,v,k);
}