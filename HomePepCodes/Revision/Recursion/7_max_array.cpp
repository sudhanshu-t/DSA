#include <iostream>
#include <climits>

using namespace std;

int max(int* arr, int n, int idx){
    if(idx == n){
        return INT_MIN;
    }

    int pot_max = max(arr, n, idx + 1);

    if(pot_max > arr[idx]){
        return pot_max;
    } else {
        return arr[idx];
    }
}

int max_val = INT_MIN;
void max_pre(int* arr, int n, int idx){
    if(idx == n){
        return;
    }
    
    if(arr[idx] > max_val){
        max_val = arr[idx];
    }
    
    max_pre(arr, n, idx + 1);
}

int main(int argc, char** argv){
    int n;
    cin >> n;
    
    int* arr = new int(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // cout << max(arr, n, 0) << endl;

    max_pre(arr, n, 0);
    cout << max_val << endl;

    return 0;
}