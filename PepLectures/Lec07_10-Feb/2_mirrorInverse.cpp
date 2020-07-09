#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int arr[100];
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        if(i != arr[arr[i]]){
            cout << "False" << endl;
            return 0;
        }
    }

    cout << "True" << endl;
    return 0;
}


/// cout << (boolalpha) << isInverse(arr, n) << endl;
/// boolalpha in the above line prints true if isInverse() returns 1 and false otherwise