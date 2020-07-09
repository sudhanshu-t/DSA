#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int arr[100], n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < (1 << n); i++){
        //Logic to print one set
        for(int b = n - 1, j = 0; b >= 0; b--, j++){
            int bm = 1 << b;

            // Logic to check set bit an printing thereby the element
            if((i & bm) == bm){
                cout << arr[j] << " ";
            } else{
                cout << "- ";
            }
        }

        cout << endl;
    }

    return 0;
}