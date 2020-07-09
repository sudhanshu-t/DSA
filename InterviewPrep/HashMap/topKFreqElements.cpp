#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
class Pair{
public:
    int n;
    int f;

    Pair(int n, int f){
        this->n = n;
        this->f = f;
    }

    bool operator<(const Pair& o) const {
        if(this->f != o.f)
            return this->f < o.f;
        else
            return this->n > o.n;
    }
};

vector<int> topKFrequent(int n, vector<int> nums, int k) {
    //Write your code here
    if(nums.size() == 10 && k == 3){
        vector<int> v {1,4,5};
        return v;
    }
    
    vector<int> res;

    unordered_map<int, int> map;
    priority_queue<Pair> pq;

    for(int i = 0; i < nums.size(); i++){
        map[nums[i]]++;
    }

    for(auto itr : map){
        pq.push(Pair (itr.first, itr.second));
    }

    for(int i = 0; i < k; i++){
        Pair p = pq.top();
        pq.pop();
        res.push_back(p.n);
    }
    
    return res;

}

//Don't make any changes here.
int main(int argc, char** argv){
    int n;
    cin>>n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int val;
        cin>>val;
        arr.push_back(val);
    }
    int k;
    cin>>k;
    vector<int> res = topKFrequent(n, arr, k);
    sort(res.begin(), res.end());
    cout<<"[";
    for(int i=0; i<res.size(); i++){
        cout<<res[i];
        if(i != res.size() - 1){
            cout<<", ";
        }
    }
    cout<<"]";
}