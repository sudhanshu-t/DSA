#include<iostream>
#include<vector>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input one array
// It should return the required output

int maxProfit(vector<int> &prices) {
    //Write your code here
}

int main(int argc,char** argv){

    int n;
    cin>>n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++){
        cin>>prices[i];
    }
    cout<<maxProfit(prices);
}