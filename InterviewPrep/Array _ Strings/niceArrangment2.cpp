#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// function to display an array.
void display(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// function to verify the result. just ignore it.
bool verify(vector<int> &arr, int N, int K) {
    if (arr.size() < N) {
        return false;
    }
    vector<bool> a(N+1);
    unordered_set<int> set;
    for (int i = 0; i < arr.size(); i++) {
        if (a[arr[i]]) {
            return false;
        } else {
            a[arr[i]] = true;
        }
        if (i == N - 1) {
            break;
        } else {
            if (set.find(abs(arr[i] - arr[i + 1])) == set.end()) {
                set.insert(abs(arr[i] - arr[i + 1]));
            }
        }
    }
    if (set.size() != K) {
        return false;
    }
    return true;
}

// This is a functional problem. You have to complete this function.
// It takes as input n and k. It should return the resultant array.
vector<int> constructArray(int n, int k) {
    vector<int> res (n);
    int left = n-k+1;
    int right = n;
    bool flag = false;

    for(int i = 0; i < n; i++){
        if(i < n - k){
            res[i] = i+1;
        }

        else {
            if(flag == true){
                res[i] = left;
                left++;
                flag = false;
            } else {
                res[i] = right;
                right--;
                flag = true;
            }
        }
    }

    return res;
}

int main(int argc, char** argv){
    int N, K;
    cin>>N>>K;

    vector<int> result = constructArray(N, K);
    if (verify(result, N, K)) {
        cout<<"Nice Arrangement";
    } else {
        cout<<"Try Harder";
    }
}