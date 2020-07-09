#include <iostream>
using namespace std;

int li_pre(int* arr, int n, int key){
    if(n == 0){
        return -1;
    }

    if(arr[n-1] == key){
        return n-1;
    } else {
        int pot_li = li_pre(arr, n-1, key);
    }
}

int li_post(int* arr, int n, int key){
    if(n == 0){
        return -1;
    }

    int pot_li = li_post(arr, n-1, key);

    if(arr[n-1] == key){
        return n-1;
    } else {
        return pot_li;
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

    cout << li_pre(arr, n, key) << endl;
    cout << li_post(arr, n, key);
}