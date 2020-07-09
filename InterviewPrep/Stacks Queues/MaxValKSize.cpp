#include <iostream>
#include <stack>
#include <vector>
#include <climits>

using namespace std;

void maxSizeK(vector<int>& arr, int k){
    vector<int> res (arr.size(), 0);
    stack<int> st;

    for(int i = arr.size() - 1; i >= 0; i--){
        while(st.size() > 0 && arr[st.top()] <= arr[i]){
            st.pop();
        }

        res[i] = (st.size() == 0) ? -1 : st.top();
        st.push(i);
    }

    // for(int i = 0; i < res.size(); i++){
    //     cout << res[i] << " ";
    // }
    // cout << endl;

    for(int i = 0; i <= res.size() - k; i++){
        int mymax = arr[res[i]];
        for(int j = i+1; j < i+k; j++){
            if(arr[res[k]] > mymax && res[k] < i+k){
                mymax = arr[res[k]];
            }
        }
        res[i] = mymax;
    }

    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
}

int main(int argc, char** argv){
    int n, k;
    cin >> n >> k;

    vector<int> arr (n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    maxSizeK(arr, k);
}