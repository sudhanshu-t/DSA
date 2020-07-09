#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// function to display an array.
void display(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// This is a functional problem. You have to complete this function.
// It takes as input an integer array. It should return
// the length of the shortest continuous subarray.
int findUnsortedSubarray(vector<int> &a) {
    vector<int> minv (a.size());
    vector<int> maxv (a.size());

    int mymin = INT_MAX;
    int mymax = INT_MIN;
    for(int i = 0; i < a.size(); i++){
        minv[minv.size() - i - 1] = min(a[a.size() - i - 1], mymin);
        mymin = minv[minv.size() - i - 1];

        maxv[i] = max(a[i], mymax);
        mymax = maxv[i];
    }

    // for(int i = 0; i < minv.size(); i++){
    //     cout << minv[i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < minv.size(); i++){
    //     cout << maxv[i] << " ";
    // }
    // cout << endl;

    int start = 0;
    int end = 0;
    for(int i = 0; i < a.size(); i++){
        if(minv[i] != maxv[i]){
            // cout << "Hello" << endl;
            // cout << minv[i] << " " << maxv[i] << endl;
            start = i - 1;
            break;
        }
    }

    // cout << start << endl;

    for(int i = a.size(); i >= 1 ; i--){
        if(minv[i-1] != maxv[i-1]){
            end = i - 1;
            break;
        }
    }

    // cout << end << " " << start << endl;
    return end - start;
}

int main(int argc, char** argv){
    int length;
    cin>>length;
    vector<int> arr(length);

    // Input for elements of array.
    for (int i = 0; i < arr.size(); i++) {
        cin>>arr[i];
    }

    cout<<findUnsortedSubarray(arr);

}