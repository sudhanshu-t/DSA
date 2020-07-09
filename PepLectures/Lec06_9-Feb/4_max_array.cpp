#include <iostream>
#include <climits>
using namespace std;

int main(int argc, char** argv){
    int arr[] = {-40, -50, -70, -90, -2, -61, -33, -14, -61};

    int max = INT_MIN, min = INT_MAX;
    for(int i = 1; i < sizeof(arr)/sizeof(int); i++){
        if(arr[i] >= max){
            max = arr[i];
        }
        if(arr[i] <= min){
            min = arr[i];
        }
    }

    cout << max << endl << min << endl;


    // Linear Search through array
    int key;
    cin >> key;

    for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
        if(arr[i] == key){
            cout << i << endl;
            return 0;
        }
    }
    cout << "Not found" << endl;
    return 0;
}