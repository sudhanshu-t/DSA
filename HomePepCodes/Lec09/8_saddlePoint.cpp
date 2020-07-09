#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int a[][3] = {
        {1,2,3},
        {4,15,6},
        {17,8,9}
    };

    int r = sizeof(a) / sizeof(a[0]);
    int c = sizeof(a[0]) / sizeof(int);

    for(int i = 0; i < r; i++){
        int min = a[i][0];
        int m_index = 0;
        
        for(int j = 1; j < c; j++){
            if(a[i][j] < min){
                min = a[i][j];
                m_index = j;
            }
        }

        int max = min;

        for(int j = 0; j < r; j++){
            if(a[j][m_index] > max){
                max = a[j][m_index];
            }
        }

        if(max == min){
            cout << "Saddle Point is: " << min << endl;
            return 0;
        }
    }

    cout << "No Saddle Point present." << endl;

    return 0;
}