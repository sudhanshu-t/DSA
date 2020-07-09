#include <iostream>
using namespace std;

void swap(int arr[], int i){
    int temp = arr[i];
    arr[i] = arr[i+1];
    arr[i+1] = temp;
}

int main(int argc, char** argv){
    int arr[] = {11, 55, 22, 33, 44};
    int n = sizeof(arr) / sizeof(int);

    for(int jc = 1; jc < n - 1; jc++){      // jc = journey counter
        for(int i = 0; i < n - jc; i++){
            if(arr[i] > arr[i+1]){
                swap(arr, i);
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}