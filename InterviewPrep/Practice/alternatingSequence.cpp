#include <bits/stdc++.h>
using namespace std;

int main(){
    // cout << (long)-1999999997 + (long)-1000000000 << endl;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> input(n);
        for(int i = 0; i < n; i++){
            cin >> input[i];
        }

        pair<long long, long> pos = make_pair(0,0);
        pair<long long, long> neg = make_pair(0,0);

        for(int i = 0; i < n; i++){
            if(input[i] > 0){
                if(neg.second + 1 > pos.second){
                    pos.first = neg.first + input[i];
                    pos.second = neg.second + 1;
                } else if(neg.second + 1 == pos.second){
                    if(neg.first + input[i] > pos.first){
                        pos.first = neg.first + input[i];
                    }
                }
            } else {
                if(pos.second + 1 > neg.second){
                    neg.first = pos.first + input[i];
                    neg.second = pos.second + 1;
                } else if(pos.second + 1 == neg.second){
                    if(pos.first + input[i] > neg.first){
                        neg.first = pos.first + input[i];
                    }
                }
            }
            // cout << pos.first << " " << pos.second << " & " << neg.first << " " << neg.second << endl;
        }

        long long int ans;
        if(pos.second > neg.second){
            ans = pos.first;
        } else if (pos.second < neg.second){
            ans = neg.first;
        } else {
            ans = max(pos.first, neg.first);
        }
        cout << ans << endl;
    }

    return 0;
}