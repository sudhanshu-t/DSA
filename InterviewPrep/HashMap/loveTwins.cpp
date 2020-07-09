#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array.
// It should return an integer value.
int mt(vector<int> &arr) {
    // Write your code here
    unordered_map<int, int> map;

    for(int i = 0; i < arr.size(); i++){
        map[arr[i]]++;
    }

    int count = 0;
    for(auto itr : map){
        count += itr.second / 2;
    }

    return count * 2;
}

int main(int argc, char** argv){
    int n;
    cin>>n;
    vector<int> arr;

    // Input for array elements.
    for (int i = 0; i < n; i++) {
        int val;
        cin>>val;
        arr.push_back(val);
    }
    cout<<mt(arr);
}