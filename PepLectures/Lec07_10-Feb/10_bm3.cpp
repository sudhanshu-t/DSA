#include <iostream>
using namespace std;
int main(int argc, char** argv){
    int arr[] = {2, 2, 2, 3, 4, 3, 4, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    int ans = 0;
    for(int i = 0; i < 32; i++){
        // Checking sum of all digits of all numbers
        int count = 0;
        int bm = 1 << i;
        for(int j = 0; j < n; j++){

            if((bm & arr[j]) == bm){
                count++;
            }
        }

        if(count%3 == 0){
            ans = 1 << i;
        }
    }

    cout << ans << endl;
    return 0;
}