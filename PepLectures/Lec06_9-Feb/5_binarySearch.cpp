#include <iostream>

using namespace std;

int main(int argc, char** argv){
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int low = 0, high = 9, mid;

    int key;
    cin >> key;
    while(low <= high){
        mid = (low + high) >> 1;

        if(arr[mid] == key){
            cout << mid << endl;
            return 0;
        } else if (arr[mid] < key){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << "Not Found" << endl;
    return 0;
}