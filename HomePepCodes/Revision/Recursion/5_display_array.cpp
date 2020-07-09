#include <iostream>
using namespace std;

void display_pre(int* arr, int n, int idx){
    if(idx == n){
        return;
    }

    cout << arr[idx] << " ";

    display_pre(arr, n, idx + 1);
}

// NOTE - The following code, takes a jump of 2 every time, hence prints only alternate numbers, all odd indices in this case

// void display_post(int* arr, int n){
//     if(n < 0){
//         return;
//     }

//     display_post(arr, n-2);

//     cout << arr[n-1] << " ";
// }

void display_post(int* arr, int n){
    if(n == 0){
        return;
    }

    display_post(arr, n-1);

    cout << arr[n-1] << " ";
}


int main(int argc, char** argv){
    int n;
    cin >> n;
    
    int* arr = new int(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    display_pre(arr, n, 0);
    cout << endl;
    display_post(arr, n);
    cout << endl;

    return 0;
}