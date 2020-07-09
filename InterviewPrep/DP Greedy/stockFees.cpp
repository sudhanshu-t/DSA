#include<iostream>
#include<vector>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array and an integer
// It should return the required output

int maxProfit(vector<int>& prices, int fee) {
    //Write your code here

    int mpb = -prices[0], mps = 0;
    
    for(int i = 1; i < prices.size(); i++){
        if(mps - prices[i] > mpb){
            mpb = mps - prices[i];
            continue;
        } else if(mpb + prices[i] - fee > mps){
            mps = mpb + prices[i] - fee;
        }
    }
    
    return mps;
}

int main(int argc,char** argv){

    int n;
    cin>>n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++){
        cin>>prices[i];
    }
    int fee;
    cin>>fee;
    cout<<maxProfit(prices,fee);
}