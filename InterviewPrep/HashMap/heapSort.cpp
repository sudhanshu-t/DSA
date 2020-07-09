#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void printArray(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}

// -----------------------------------------------------
// This is a functional problem. Only these functions have to be written.
// This function takes as input an array.

void sort(vector<int> &arr) {
    //Write your code here
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < arr.size(); i++){
        pq.push(arr[i]);
    }

    int i = 0;
    while(pq.size()){
        // arr[i] = pq.top();
        // pq.pop();

        arr[i] = pq.top();
        pq.pop();
        i++;
    }
}

void heapify(vector<int> &arr, int n, int i) {
    //Write your code here
}

// -----------------------------------------------------

int main(int argc, char** argv){
    int n; 
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int val; cin>>val;
        arr.push_back(val);
    }
    sort(arr);  
    printArray(arr); 
}