#include<iostream>
using namespace std;

int main(int argc, char** argv){
    int a1[] = {3,2,7,9,8};
    int a2[] = {9,7,8,3,2,1};

    int n1 = sizeof(a1) / sizeof(int);
    int n2 = sizeof(a2) / sizeof(int);

    int n = (n1 >= n2) ? n1 + 1 : n2 + 1;

    cout << n << endl;

    int a[n] = {0};

    int safe = n, c = 0, i1 = n1-1, i2 = n2-1;
    while(n >= 1){
        int val = 0;
        if(i1 < 0 && i2 < 0){
            val = c;
        }

        else if(i2 < 0 && i1 >= 0){
            val = c + a1[i1];
        }

        else if(i1 < 0 && i2 >= 0){
            val = c + a2[i2];
        }
        
        else
            val = c + a1[i1] + a2[i2];
        
        if(val >= 10){
            a[n-1] = val - 10;
            c = 1;
        } else {
            a[n-1] = val;
            c = 0;
        }

        n--;
        i1--;
        i2--;
    }

    n = safe;

    for(int i = 0; i < n; i++){
        cout << a[i];
    }

    cout << endl;

    return 0;
}
