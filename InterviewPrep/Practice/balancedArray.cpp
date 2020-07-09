#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int half = n/2;
        if(half % 2 != 0){
            cout << "NO" << endl;
            continue;
        }

        vector<long long> arr (n);
        int ce = 2;
        int co = 1;
        int se = 0;
        int so = 0;

        for(int i = 0; i < n/2; i++){
            if(i == 0){
                arr[i] = ce;
                arr[i+n/2] = co;
                ce += 2;
                co += 2;
                se += ce;
                so += co;
                continue;
            }

            if(se > so){
                int diff = se-so;
                arr[i] = ce;
                co = ce + diff;
                arr[i+n/2] = co;
                se += ce;
                so += co;
                ce += 2;
                co += 2;
            } else if(se < so) {
                int diff = so-se;
                arr[i+n/2] = co;
                ce = co + diff;
                arr[i] = ce;
                se += ce;
                so += co;
                ce += 2;
                co += 2;
            } else {
                arr[i] = ce;
                arr[i+n/2] = co;
                se += ce;
                so += co;
                ce += 2;
                co += 2;
            }
        }

        cout << "YES" << endl;
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}