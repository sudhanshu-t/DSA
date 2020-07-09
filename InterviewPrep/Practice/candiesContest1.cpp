#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int k = 2;

        while(true){
            int ans;
            int div = pow(2, k)-1;
            // cout << "div " << div << endl;
            if(n % div == 0){
                ans = n / div;
                // cout << n << " " << div << endl;
                cout << ans << endl;
                break;
            }
            k++;
        }
    }
}