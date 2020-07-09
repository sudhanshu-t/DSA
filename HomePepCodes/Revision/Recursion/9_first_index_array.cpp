#include <iostream>
using namespace std;

int f_idx(int* arr, int n, int idx, int key){
    if(idx == n){
        return -1;
    }

    int pot_fi = f_idx(arr, n, idx + 1, key);

    if(arr[idx] == key){
        return idx;
    } else {
        return pot_fi;
    }
}

int fi_pre(int* arr, int n, int idx, int key){
    if(idx == n){
        return -1;
    }

    if(arr[idx] == key){
        return idx;
    } else {
        return fi_pre(arr, n, idx + 1, key); 
    }
    
}

int main(){
    int n;
    cin >> n;

    int* arr = new int(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int key;
    cin >> key;

    cout << f_idx(arr, n, 0, key) << endl;
    cout << fi_pre(arr, n, 0, key) << endl;
}