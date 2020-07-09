#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input a deck of cards
// It should return the answer deck
vector<int> deckRevealedIncreasing(vector<int>& nums) {
//Write your code here	 	 
    queue<int> q;

    for(int i = 0; i < nums.size(); i++){
        q.push(i);
    }

    vector<int> idxarr;

    while(q.size() != 0){
        int front = q.front();
        q.pop();

        idxarr.push_back(front);

        front = q.front();
        q.pop();
        q.push(front);
    }

    vector<int> res (nums.size());
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++){
        res[idxarr[i]] = nums[i];
    }

    return res;
}

//Don't make any changes here.
int main(int argc,char** argv){
    int n;
    cin>>n;
    vector<int> Input(n);
    for(int i=0;i<n;i++){
        cin>>Input[i];
    }
    vector<int> ans = deckRevealedIncreasing(Input);
    for (int i : ans) {
        cout<<i<<" ";
    }

}