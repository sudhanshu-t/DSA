#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int arr[100], n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int r;
    cin >> r;

    r = (r < 0)? n + r : r;

    int temp;
    int start = 0, end = n-r-1;
    while(start < end){
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    start = n - r;
    end = n - 1;
    while(start < end){
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    start = 0;
    end = n - 1;
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
}