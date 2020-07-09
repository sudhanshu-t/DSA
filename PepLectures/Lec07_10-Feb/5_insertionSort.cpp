#include <iostream>
using namespace std;

void swap(int arr[], int i){
    int temp = arr[i];
    arr[i] = arr[i-1];
    arr[i-1] = temp;
}

int main(int argc, char** argv){
    int arr[] = {11, 2, 44, 33, 7};
    int n = sizeof(arr) / sizeof(int);

    for(int jc = 1; jc <= n - 1; jc++){
        for(int i = jc; i > 0; i--){
            if(arr[i] < arr[i-1]){
                swap(arr, i);
            } else {
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }

    return 0;
}