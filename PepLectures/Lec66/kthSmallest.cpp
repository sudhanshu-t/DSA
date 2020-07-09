#include <iostream>
using namespace std;

int partition(int* arr, int lo, int hi){
    int pivot = arr[hi];

    int i = lo, j = lo;

    while(j <= hi){
        if(arr[j] > pivot){
        } else {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
        }
        j++;
    }

    return i - 1;
}

int kthSmallest(int* arr, int lo, int hi, int k){
    if(lo < hi){
        int pi = partition(arr, lo, hi);
        if(pi + 1 == k){
            return arr[pi];
        }

        if(k < pi + 1){
            return kthSmallest(arr, lo, pi - 1, k);
        }
        else {
            return kthSmallest(arr, pi + 1, hi, k);
        }
    }
}

int main(int argc, char** argv){
    int* arr = new int[8] {1,2,3,4,7,6,5,9};
    cout << kthSmallest(arr, 0, 7, 3) << endl;

    for(int i = 0; i < 8; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}