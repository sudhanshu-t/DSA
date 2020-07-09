#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int a[] = {2,3,3,4,2,2,2,2,2,2,21,2,1,2,2,2,2,6};
    int n = sizeof(a) / sizeof(int);

    cout << n << endl;

    int m = a[0], count = 1;

    for(int i = 1; i < n; i++){
        if(m == a[i]){
            count++;
        }

        else{
            count--;

            if(!count){
                m = a[i];
                count = 1;
            }
        }
    }

    cout << count << endl;

    count = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == m){
            count++;
        }
    }

    if(count > n / 2)
        cout << m << endl;
    else 
        cout << -1 << endl;

    return 0;
}