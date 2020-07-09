#include<iostream>
#include<vector>
using namespace std;

//This is a functional problem, complete this function only.
void rotate(vector<int> &a, int k) {
    k = a.size() - k;
    
    for(int i = 0; i < k / 2; i++){
        int temp = a[i];
        a[i] = a[k - i - 1];
        a[k - i - 1] = temp;
    }

    for(int i = 0; i < (a.size() - k) / 2; i++){
        int temp = a[i+k];
        a[i+k] = a[a.size() - i - 1];
        a[a.size() - i - 1] = temp;
    }

    for(int i = 0; i < a.size() / 2; i++){
        int temp = a[i];
        a[i] = a[a.size() - i - 1];
        a[a.size() - i - 1] = temp;
    }
}

// Don't make any changes here
int main(int argc, char** argv){
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    rotate(arr, k);
    for (int v : arr)
        cout<<v<<" ";
}