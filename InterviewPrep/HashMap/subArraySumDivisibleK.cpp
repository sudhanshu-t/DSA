#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
int subarraysDivByK(vector<int> A, int k) {
    //write your code here
    unordered_map<int, int> fmap;

    int sum = 0;
    int count = 0;
    fmap[0] = 1;

    for(int val : A){
        sum += val;

        if(sum < 0){
            fmap[(sum % k + k) % k]++;
            // cout << sum % k + k << " increments" << endl;
            count += fmap[(sum % k + k) % k] - 1;
        } else {
            fmap[sum % k]++;
            // cout << sum % k << " increments" << endl;
            count += fmap[sum % k] - 1;
        }
    }

    return count;
}

// -----------------------------------------------------

int main(int argc, char** argv){
    int n, k;
    cin>>n>>k;
    vector<int> arr;
    for (int z = 0; z < n; z++) {
        int val;
        cin>>val;
        arr.push_back(val);
    }
    cout<<subarraysDivByK(arr, k);

    // cout << -11 % 5 << endl;
}