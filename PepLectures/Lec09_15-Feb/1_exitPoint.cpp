#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int a[4][4] = {
        {0,0,1,0},
        {1,0,0,0},
        {0,0,0,0},
        {1,0,1,0}
    };

    int r = sizeof(a) / sizeof(a[0]);
    int c = sizeof(a[0]) / sizeof(int);

    int i = 0, j = 0;
    int d = 0;

    while(1){

        d = (d + a[i][j]) % 4;

        // East direction
        if(d == 0){
            if(j < c - 1)
                j++;
            else
            {
                break;
            }
            
        }

        // South direction
        else if(d == 1){
            if(i < r - 1){
                i++;
            }
            else{
                break;
            }
        }


        else if(d == 2){
            if(j > 0){
                j--;
            } else{
                break;
            }
        }

        else if(d == 3){
            if(i > 0){
                i--;
            } else{
                break;
            }
        }
    } 

    cout << i << " " << j << endl;
    return 0;
}



// #include <iostream>
// using namespace std;

// int main(int argc, char** argv){
//     int a[4][4] = {
//         {0,0,1,0},
//         {1,0,0,0},
//         {0,0,0,0},
//         {1,0,1,0}
//     };

//     int r = sizeof(a) / sizeof(a[0]);
//     int c = sizeof(a[0]) / sizeof(int);

//     int ones = 0;
//     for(int i = 0; i < r; i++){
//         for(int j = 0; j < c; j++){
//             if(a[i][j] == 1){
//                 ones++;
//             }
//         }
//     }

//     bool i_incr = false;
//     bool j_incr = false;
//     int i = 0, j = 0;
//     while(i < r && j < c){
//         while(a[i][j] == 0 && i < r && j < c){
//             if(!j_incr)
//                 j++;
//             else
//             {
//                 j--;
//             }
//         }
        
//         j_incr = true;
//         ones--;

//         while(a[i][j] == 0 && i < r && j < c){
//             if(!i_incr)
//                 i++;
//             else
//             {
//                 i--;
//             }
//         }
        
//         i_incr = true;
//         ones--;
//     }
    
//     cout << i - 1 << endl;
//     cout << j - 1 << endl;
// }
