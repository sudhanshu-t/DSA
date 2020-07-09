#include<iostream>
using namespace std;

int main(){
    int n, r, nod = 0;

    cin>>n>>r;

    int safe = n;

    // Counting no. of digits
    while(n != 0){
        n = n/10;
        nod++;
    }

    n = safe;

    r = r%nod;
    r = (r<0)?r+nod:r;

    int d=1, m=1;

    for(int i = 0; i<nod; i++){
        if(i < r){
            d = d*10;
        } else{
            m = m*10;
        }
    }

    int q = n/d;
    int rem = n%d;

    int ans = q + rem*m;

    cout<<ans<<endl;
}