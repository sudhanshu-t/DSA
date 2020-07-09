#include <iostream>
#include <vector>

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

void quickSort(int* arr, int lo, int hi){
    if(lo < hi){
        int pi = partition(arr, lo, hi);

        quickSort(arr, lo, pi - 1);
        quickSort(arr, pi + 1, hi);
    }
}

int main(int argc, char** argv){
    int* arr = new int[8] {1,9,0,6,5,4,4,7};

    quickSort(arr, 0, 7);

    for(int i = 0; i < 8; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}