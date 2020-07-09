#include<iostream>
#include<vector>
using namespace std;

// function to display an array.
void display(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// This is a functional problem. You have to complete this function.
// It takes as input an integer array. It should return the maximum profit.
int maxProfit(vector<int> &A) {
    // write your code here.
    int mymax = 0;

    for(int i = 0; i < A.size() - 1; i++){
        if(A[i+1] > A[i]){
            mymax += A[i+1] - A[i];
        }
    }

    return mymax;
}

int main(int argc, char** argv){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++) {
        cin>>arr[i];
    }

    cout<<maxProfit(arr);
}