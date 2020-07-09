#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int n;
    cin >> n;

    int bm;
    for(int i = 31; i >= 0; i--){
        bm = 1 << i;

        // if((n & bm) == 0)
        //     cout << "0";
        // else
        //     cout << "1"; 

        cout << ((n & bm) == 0 ? 0 : 1);       
    }

    cout << endl;
    return 0;
    
}
