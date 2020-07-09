#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int t, a[2000002];
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        int u = 0;
        for(int i = 0; i < n; i++){
            u ^= a[i];
        }
        
        int rsbm = u & (-u);
        
        int u1 = 0, u2 = 0;
        for(int i = 0; i < n; i++){
            if((a[i] & rsbm) == rsbm){
                u1 ^= a[i];
            }
            
            else {
                u2 ^= a[i];
            }
        }

        if(u1 < u2){
            cout << u1 << " " << u2 << endl;
        }
        else {
            cout << u2 << " " << u1 << endl;
        }        
    }

    return 0;
}