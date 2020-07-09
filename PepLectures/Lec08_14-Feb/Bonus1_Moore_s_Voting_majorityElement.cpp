#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int arr[] = {1,1,1,1,1,3,2,2,2,2,2,2,2,2,2,1,1,2,3};
    int n = sizeof(arr) / sizeof(int);
    cout << n << endl;

    int count = 0;
    int maj = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] == maj){
            count++;
        } else {
            count--;
            if(count == 0){
                maj = arr[i];
                count++;
            }
        }
    }

    count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == maj)
            count++;
    }

    if(count > n / 2)
        cout << maj << endl;

    else
        cout << "No Majority Element" << endl;
    
}