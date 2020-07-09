#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// function to display an array.
void display(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


// utility function, don't change the code of it.
vector<int> sortResultEvenOdd(vector<int> &arr) {
    int i = 0;

    while (i < arr.size()) {
        if (arr[i] % 2 != 0) {
            sort(arr.begin(), arr.begin() + i);
            sort(arr.begin() + i, arr.end());
            return arr;
        }
        i++;
    }

    sort(arr.begin(), arr.end());
    return arr;

}

// This is a functional problem. You have to complete this function.
// It takes as input an integer array. It should return
// the required array.
vector<int> sortArrayByParity(vector<int> &a) {
    int i = 0, j = 0;

    while(j < a.size()){
        if(a[j] % 2 == 0){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j++;
        } else {
            j++;
        }
    }

    return a;
}

int main(int argc, char** argv){
    int length;
    cin>>length;
    vector<int> arr(length);

    // Input for elements of array.
    for (int i = 0; i < arr.size(); i++) {
        cin>>arr[i];
    }

    vector<int> result = sortArrayByParity(arr);
    vector<int> sortedResult = sortResultEvenOdd(result);
    display(sortedResult);
}