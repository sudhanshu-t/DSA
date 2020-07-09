#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int arr[] = {2, 5, 7, 9, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    int start, end;
    cin >> start >> end;

    // Reverse from start to end and print
    // int temp;
    // for(int i = start; i <= end; i++){
    //     temp = arr[i];
    //     arr[i] = arr[end - i + 1];
    //     arr[end - i + 1] = temp;
    // }

    int temp;
    while(start < end){
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}