#include<iostream>
using namespace std;

int main(int argc, char** argv){
    int n;
    cin >> n;

    for(int r = 0; r <= n; r++){
        int nck = 1;
        for(int c = 0; c <= r; c++){
            cout<<nck<<"\t";
            nck = (nck * (r-c)) / (c+1);
            
        }

        cout<<endl;
    }
    
    return 0;
}
// reviewed