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

    int maxr = r-1, minr = 0, maxc = c-1, minc = 0;

    while(maxr >= minr){
        int safe = maxr;

        if((maxr&1) == 0){
            minc = 0;

            while(maxr < r){
                cout << a[maxr][minc] << " ";
                
                minc++;
                maxr++;
            }
        }

        else {
            minc = r - maxr - 1;
            maxr = r-1;

            while(minc >= 0){
                cout << a[maxr][minc] << " ";

                minc--;
                maxr--;
            }

        }

        maxr = safe;
        maxr--;
    }

    cout << endl;

    return 0;
}