#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int a[][5] = {
		{1,6,7,12,13},
		{2,5,8,11,14},
		{3,4,9,10,15}
	};

    int r = sizeof(a) / sizeof(a[0]);
    int c = sizeof(a[0]) / sizeof(int);

    for(int j = 0; j < c; j++){
        if((j & 1) == 0)
            for(int i = 0; i < r; i++){
                cout << a[i][j] << " ";
            }

        else
            for(int i = r-1; i >= 0; i--){
                cout << a[i][j] << " ";
            }

        cout << endl;
    }

    return 0;
}