#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written
// This function takes as input an array
// It should return required output

int maxChunksToSorted(vector<int> &arr) {
    vector<int> minv (arr.size());
    vector<int> maxv (arr.size());

    // MAX ARRAY
    maxv[0] = INT_MIN;
    for(int i = 1; i < maxv.size(); i++){
        maxv[i] = max(arr[i-1], maxv[i-1]);
    }

    // MIN ARRAY
    minv[minv.size() - 1] = arr[arr.size() - 1];
    for(int i = arr.size() - 2; i >= 0; i--){
        minv[i] = min(minv[i+1], arr[i]);
    }

    int count = 0;
    for(int i = 0; i < arr.size(); i++){
        if(minv[i] >= maxv[i]){
            count++;
        }
    }

    return count;
}

int main(int argc, char** argv){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<maxChunksToSorted(a);
}