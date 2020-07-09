#include <iostream>
using namespace std;

bool find132pattern(int* arr, int n){
    // Write your code here

    int prev = 0;
    int curr = 1;
    int next = 2;

    if(n == 0 || n == 1 || n == 2){
        return false;
    }

    while(next != n){
        if(arr[prev] < arr[next] && arr[next] < arr[curr]){
            return true;
        }

        curr++;
        next++;
        prev++;
    }

    return false;
}

//Dont make changes here
int main() {

    int n; cin >> n;
    int* A = new int[n];
    for(int i=0;i<n;i++)
        cin >> A[i];
    cout << find132pattern(A, n) << endl;
}

