#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// This is a functional problem. You have to complete this function.
    // It takes as input two arrays and k.
    // It should return list of k lists of pairs with smallest sum.
class Pair{
public:
    int p1;
    int p2;

    Pair(int p1, int p2){
        this->p1 = p1;
        this->p2 = p2;
    }

    bool operator>(const Pair& o) const{
        return this->p1 + this->p2 > o.p1 + o.p2;
    }
};
    
vector<vector<int> > kSmallestPairs(vector<int>& num1,vector<int> &num2 ,int k){
    // write your code here.
    vector<vector<int>> ans;
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

    for(int i = 0; i < num1.size(); i++){
        for(int j = 0; j < num2.size(); j++){
            pq.push(Pair (num1[i], num2[j]));
        }
    }

    for(int i = 0; i < k; i++){
        Pair p = pq.top(); pq.pop();
        vector<int> temp (2);
        temp[0] = p.p1;
        temp[1] = p.p2;
        ans.push_back(temp);
    }

    return ans;
}

void display(vector<vector<int> > &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool sortcol( const vector<int>& l1, 
            const vector<int>& l2 ) { 
    int sum1 = l1[0] + l1[1];
    int sum2 = l2[0] + l2[1];

    if (sum1 != sum2) {
        return sum1 <sum2;
    } else {
        return l1[0]< l2[0];
    }

} 
int main(int argc,char ** argv){

    int n;
    cin>>n;
    vector<int> num1;
    vector<int> num2;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        num1.push_back(a);
    }
    
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        num2.push_back(a);
    }
    
    int k;
    cin>>k;
    vector<vector<int> > res;
    res=kSmallestPairs(num1, num2, k);
    sort(res.begin(),res.end(),sortcol);
    display(res);
}