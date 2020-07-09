#include <iostream>
using namespace std;

void disp_rev_pre(int* arr, int n, int idx){
    if(idx == n){
        return;
    }

    cout << arr[n - idx - 1] << " ";
    disp_rev_pre(arr, n, idx + 1);
}

void disp_rev_post(int* arr, int n, int idx){
    if(idx == n){
        return;
    }

    disp_rev_post(arr, n, idx + 1);

    cout << arr[idx] << " ";
}

int main(int argc, char** argv){
    int n;
    cin >> n;
    
    int* arr = new int(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    disp_rev_pre(arr, n, 0);
    cout << endl;
    disp_rev_post(arr, n, 0);
    cout << endl;

    return 0;
}