#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int arr[100];

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Print last occurence
    int low = -1, high = n - 1, mid;
    int rmo, key;
    cin >> key;

    while(low <= high){
        mid = (low + high) >> 1;

        if(key == arr[mid]){
            rmo = mid;
            low = mid + 1;
        } else if(key > arr[mid]){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << rmo << endl;
}