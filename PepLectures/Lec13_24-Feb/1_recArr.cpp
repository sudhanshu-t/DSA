#include <iostream>
using namespace std;

void display(int* arr, int n, int vidx){
    if(vidx == n){
        return;
    }

    cout << arr[vidx] << " ";
    display(arr, n, vidx+1);
}



void displayReverse(int* arr, int n, int vidx){
    if(vidx <= 0){
        return;
    }

    cout << arr[vidx-1] << " ";
    displayReverse(arr, n, vidx-1);
}



void displayReverse2(int* arr, int n, int vidx){
    if(vidx == n){
        return;
    }

    displayReverse2(arr, n, vidx+1);
    cout << arr[vidx] << " ";
}



int max(int* arr, int n, int vidx){
    if(vidx == n-1){
        return arr[vidx];
    }

    int max1 = max(arr, n, vidx+1);

    if(arr[vidx] > max1){
        return arr[vidx];
    }

    else {
        return max1;
    }
}



bool find(int* arr, int n, int vidx, int d){
    if(vidx == n){
        return false;
    }

    if(find(arr, n, vidx+1, d)){
        return true;
    }
    else {
        if(arr[vidx] == d)
            return true;
        else
            return false;
    }
}



int fi(int* arr, int n, int vidx, int d){
    if(vidx == n){
        return -1;
    }
    
    if(arr[vidx] == d){
        return vidx;
    }
    else {
        return fi(arr, n, vidx+1, d);
    }
}



int li(int* arr, int n, int vidx, int d){
    if(n < 0){
        return -1;
    }

    if(arr[n] == d){
        return n;
    }
    else {
        return li(arr, n-1, vidx, d);
    }
}


int* allIndices(int* arr, int n, int vidx, int d, int* p){
    if(n < 0){
        int* ans = NULL;
        return ans;
    }

    int* a = allIndices(arr, n-1, 0, d, p);

    if(arr[n] == d){
        *p = *p + 1;
        int* a1 = new int[*p];

        a1[*p - 1] = n;
        for(int i = 0; i < *p-1; i++){
            a1[i] = a[i];
        }

        return a1; 
    }

    return a;
}


void pp1(int r, int c, int n){


    pp1(1, 0, n);

    

    
}


int main(int argc, char** argv){
    int n;
    cin >> n;

    int* arr = new int[n];

    for(int i = 0; i  < n; i++){
        cin >> arr[i];
    }

    display(arr, n, 0);
    // displayReverse(arr, n, n);
    // displayReverse2(arr, n, 0);
    // cout << max(arr, n, 0);
    
    // int d;
    // cin >> d;

    // cout << find(arr, n, 0, d);

    // cout << fi(arr, n, 0, d);
    // cout << li(arr, n, 0, d);
    
    // int n1 = 0;
    // int* a1 = allIndices(arr, n, 0, 2, &n1);
    
    // for(int i = 0; i < n1; i++){
    //     cout << a1[i] << " ";
    // }
    

    // int n; 
    // cin >> n;

    // pp1(0, 0, n);

    // cout << endl;
}