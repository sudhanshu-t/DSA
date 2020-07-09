#include <iostream>
using namespace std;

int inversionCount(int* arr, int lo, int hi){
    int mid = (lo + hi) / 2;

    int i = lo;
    int j = mid + 1;

    int k = 0;

    int* nArr = new int[hi - lo + 1];

    int count = 0;

    while(i <= mid && j <= hi)
        if(arr[i] > arr[j]){
            nArr[k++] = arr[j++];
            count += mid + 1 - i;
        }
        else
            nArr[k++] = arr[i++];

    while(i <= mid)
        nArr[k++] = arr[i++];

    while(j <= hi)
        nArr[k++] = arr[j++];

    // for(i = lo; i <= hi; i++){
    //     arr[i] = nArr[i - lo];
    //     cout << arr[i] << " ";
    // }

    delete[] nArr;

    return count;
    // cout << endl;
}

int mergeSort(int* arr, int lo, int hi){
    if(lo == hi){
        return 0;
    }

    int mid = (lo + hi) / 2;
    int lc = mergeSort(arr, lo, mid);
    int rc = mergeSort(arr, mid + 1, hi);

    int mc = inversionCount(arr, lo, hi);

    return lc + rc + mc;
}

int main(int argc, char** argv){
    int* arr = new int[8] {2,6,8,1,3,4,7,5};

    cout << mergeSort(arr, 0, 7) << endl;
}