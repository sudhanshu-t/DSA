#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int arr[] = {2, 3, 2, 6, 4, 6, 5, 3, 5};
    int n = sizeof(arr) / sizeof(int);

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans ^= arr[i];
    }

    cout << ans << endl;

    return 0;
}