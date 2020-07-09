#include <iostream>
using namespace std;

int main(){
    int arr[] = {4, 2, 0, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    int inv[n];

    for(int i = 0; i < n; i++){
        inv[arr[i]] = i;

        cout << arr[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < n; i++){
        cout << inv[i] << " ";
    }
    return 0;
}