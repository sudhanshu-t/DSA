#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int a[][5] = {
        {1,2,3,4,5},
        {2,3,4,5,6},
        {13,4,5,6,7},
        {4,15,6,7,8},
        {5,6,17,8,9}
    };

    int r = sizeof(a) / sizeof(a[0]);
    int c = sizeof(a[0]) / sizeof(int);


    int maxr = r-1, maxc = c-1, minc = 0, minr = 0;

    while(maxr >= minr){
        minc = 0;
        int safe = maxr;

        while(maxr < r){
            cout << a[maxr][minc] << " ";

            maxr++;
            minc++;
        }

        maxr = safe;
        maxr--;
    }

    cout << endl;

    return 0;
}