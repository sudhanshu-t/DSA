#include <iostream>
using namespace std;

void disp(int arr[], int vidx, int n){
    // w/o vidx
    // if(n == 0){
    //     return;
    // }

    // disp(arr, n - 1);
    // cout << arr[n-1] << endl;

    // w/ vidx
    // if(vidx == n){
    //     return;
    // }

    // proactive

    cout << arr[vidx] << endl;

    if(vidx + 1 < n)
        disp(arr, vidx + 1, n);   
}

void dispRev(int arr[], int vidx, int n){
    if(vidx == n){
        return;
    }

    dispRev(arr, vidx + 1, n);
    cout << arr[vidx] << endl;
}

int max(int arr[], int vidx, int n){
    if(vidx == n - 1){
        return arr[vidx];
    }

    int m = max(arr, vidx+1, n);

    if(arr[vidx] > m){
        return arr[vidx];
    } else {
        return m;
    }
}

bool find(int arr[], int vidx, int n, int k){
    if(vidx == n){
        return false;
    }

    bool found = find(arr, vidx+1, n, k);

    if(found == true){
        return true;
    } else {
        if(arr[vidx] == k){
            return true;
        }
    }

    return false;

}

int fi(int arr[], int sp, int n, int k){
    if(sp == n){
        return -1;
    }

    int f = fi(arr, sp + 1, n, k);

    if(arr[sp] == k){
        return sp;
    } 

    return f;
}

int li(int arr[], int sp, int n, int k){
    if(sp == n){
        return -1;
    }

    int l = li(arr, sp, n-1, k);
    if(arr[n] == k){
        return n;
    }

    return l;
} 

int* allInd(int arr[], int sp, int n, int k, int* p){
    if(sp == n){
        int* bres = NULL;
        return bres;
    }

    int* a = allInd(arr, sp+1, n, k, p);

    if(arr[sp] == k){
        *p = *p + 1;
        // int ans[*p]; // dangling pointer

        int* ans = new int[*p];

        ans[0] = sp;

        for(int i = 1; i < *p; i++){
            ans[i] = a[i-1];
        }

        return ans;
    }

    return a;
}

int main(int argc, char** argv){
    int arr[] = {0,1,1,2,3,1,4,1,5};
    int n = sizeof(arr) / sizeof(int);
    
    // disp(arr, 0, n);
    // dispRev(arr, 0, n);
    // cout << max(arr, 0, n) << endl;
    // cout << find(arr, 0, n, 15) << endl;
    // cout << fi(arr, 0, n, 1) << endl;
    // cout << li(arr, 0, n, 1) << endl;
    
    int c = 0;
    int* a = allInd(arr, 0, n, 1, &c);

    cout << c << endl;
    for(int i = 0; i < c; i++){
        cout << a[i] << endl;
    }

    return 0;
}