#include <iostream>
using namespace std;

bool find(int* arr, int n, int idx, int key){
    if(idx == n){
        return false;
    }

    int ans1 = find(arr, n, idx + 1, key);

    if(ans1 == true){
        return true;
    } else {
        if(arr[idx] == key){
            return true;
        } else {
            return false;
        }
    }
}

int main(int argc, char** argv){
    int n;
    cin >> n;
    
    int* arr = new int(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int key;
    cin >> key;

    cout << find(arr, n, 0, key) << endl;

    return 0;
}