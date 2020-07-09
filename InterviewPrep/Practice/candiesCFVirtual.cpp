#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans;
        if(n%2 == 0){
            ans = n/2-1;
        } else {
            ans = n/2;
        }
        cout << ans << endl;
    }
}