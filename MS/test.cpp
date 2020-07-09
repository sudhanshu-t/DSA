#include <iostream>
using namespace  std;

int randFunc(int lo, int hi){
    // hi - exclusive

    int k = rand() % hi + lo;
    return k;
}

int* shuffle(int* arr, int n){
    if(n == 1){
        return arr;
    }
    
    int* smallShuffle = shuffle(arr, n - 1);

    int k = randFunc(0, n);

    int temp = arr[k];
    arr[k] = arr[n - 1];
    arr[n - 1] = temp;

    return arr;
}

void print(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void downHeapify(int* arr, int n, int i){
    int largest = i;
    int li = 2 * i + 1;
    int ri = 2 * i + 2;

    if(li < n && arr[li] > arr[largest]){
        largest = li;
    }

    if(ri < n && arr[ri] > arr[largest]){
        largest = ri;
    }

    if(largest != i){
        swap(arr, i, largest);
        downHeapify(arr, n, largest);
    }
}

void heapSort(int* arr, int n){
    for(int i = n/2 - 1; i >= 0; i--){
        downHeapify(arr, n, i);
    }

    for(int i = n-1; i >= 0; i--){
        swap(arr, i, 0);
        downHeapify(arr, i, 0);
    }
}

bool main(){
    int arr[] = {1,4,2,3,7,6,4,3};
    int n = sizeof(arr) / sizeof(int);

    heapSort(arr, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    // int* arr = new int[6]{1,2,3,4,5,6};
    // arr = shuffle(arr, 6);
    // print(arr, 6);
    // arr = shuffle(arr, 6);
    // print(arr, 6);
    // arr = shuffle(arr, 6);
    // print(arr, 6);
    // arr = shuffle(arr, 6);
    // print(arr, 6);
    // arr = shuffle(arr, 6);
    // print(arr, 6);
    // arr = shuffle(arr, 6);
    // print(arr, 6);
    // arr = shuffle(arr, 6);
    // print(arr, 6);

    
    // int i = 1;
    // char* c = (char*)&i;

    // if(*c)
    //     cout << "Little" << endl;
    // else
    //     cout << "Big" << endl;

    // int** arr = new int*[10];

    // for(int i = 0; i < 10; i++){
    //     arr[i] = new int[5];
    // }

    // for(int i = 0; i < 10; i++){
    //     for(int j = 0; j < 5; j++){
    //         arr[i][j] = (i + 1) * (j + 1);
    //     }
    // }

    // for(int i = 0; i < 10; i++){
    //     for(int j = 0; j < 5; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // string s;
    // getline(cin, s);

    // char arr[100];
    // cin.getline(arr, 100);

    
    // cout << arr << endl;
}