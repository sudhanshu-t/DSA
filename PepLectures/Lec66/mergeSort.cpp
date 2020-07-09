#include <iostream>

using namespace std;

void merge(int* arr, int lo, int hi){
    int mid = (lo + hi) / 2;

    int i = lo;
    int j = mid + 1;

    int k = 0;

    int* nArr = new int[hi - lo + 1];

    while(i <= mid && j <= hi)
        if(arr[i] > arr[j])
            nArr[k++] = arr[j++];
        else
            nArr[k++] = arr[i++];

    while(i <= mid)
        nArr[k++] = arr[i++];

    while(j <= hi)
        nArr[k++] = arr[j++];

    for(i = lo; i <= hi; i++){
        arr[i] = nArr[i - lo];
        cout << arr[i] << " ";
    }

    delete[] nArr;

    cout << endl;
}

void mergeSort(int* arr, int lo, int hi){
    if(lo == hi){
        return;
    }

    int mid = (lo + hi) / 2;
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid + 1, hi);

    merge(arr, lo, hi);
}

int main(int argc, char** argv){
    int* arr = new int[8] {2,6,8,1,3,4,7,5};

    mergeSort(arr, 0, 7);

    for(int i = 0; i < 8; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}