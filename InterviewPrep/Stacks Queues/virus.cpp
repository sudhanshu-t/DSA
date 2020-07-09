#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

void virus(vector<int>& arr){
    stack<int> st;
    int mymax = INT_MIN;
    
    vector<int> res (arr.size(), -1);
    for(int i = arr.size() - 1; i >= 0; i--){
        while(st.size() > 0 && arr[st.top()] <= arr[i]){
            st.pop();
        }
        
        if(st.size() != 0){
            res[i] = st.top() - i - 1;
            mymax = max(res[i], mymax);
        }
        st.push(i);
    }
    
    cout << mymax << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    vector<int> arr (100000);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    virus(arr);
    
    return 0;
}
