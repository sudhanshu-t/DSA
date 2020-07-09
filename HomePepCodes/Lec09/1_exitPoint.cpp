#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int a[][4] = {
		{0,0,1,0},
		{1,0,0,0},
		{1,0,1,0}
	};

    int r = sizeof(a) / sizeof(a[0]);
    int c = sizeof(a[0]) / sizeof(int);

    int d = 0;
    int i = 0, j = 0;
    while(true){
        d = (d + a[i][j]) % 4;

        if(d == 0){
            // Move East

            if(j < c - 1)
                j++;
            else
                break;
        }

        else if(d == 1){
            // Move South

            if(i < r - 1)
                i++;
            else
                break;
        }

        else if(d == 2){
            // Move West

            if(j > 0)
                j--;
            else
                break;
        }

        else {
            // Move North

            if(i > 0)
                i--;
            else
                break;
        }
    }

    cout << "(" << i << ", " << j << ")" << endl;

    return 0;
}