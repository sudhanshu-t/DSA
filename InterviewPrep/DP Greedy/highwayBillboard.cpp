#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// O(n2)
int billboard(vector<int>& x, vector<int>& r, int M, int t){
    vector<int> strg (x.size(), 0);

    int globalMax = INT_MIN;
    strg[0] = r[0];
    for(int i = 1; i < strg.size(); i++){
        strg[i] = r[i];
        int myMax = INT_MIN;
        for(int j = 0; j < i; j++){
            if(x[i] - x[j] > t){
                myMax = max(myMax, strg[j]);
            }
        }

        if(myMax != INT_MIN){
            strg[i] += myMax;
        }

        globalMax = max(globalMax, strg[i]);
    }

    return globalMax;
}

// O(M)
int highway(vector<int>& x, vector<int>& r, int M, int t){
    vector<int> strg (M + 1);

    for(int i = 0; i < r.size(); i++){
        strg[x[i]] = r[i];
    }
    
    int myMax = 0;
    for(int i = 0; i <= M; i++){
        int pot = strg[i] + ((i - t - 1 >= 0) ? strg[i - t - 1] : 0);

        // cout << "pot " << pot << endl;
        if(pot > myMax){
            myMax = pot;
        }

        strg[i] = myMax;
    }

    // for(int i = 0; i < strg.size(); i++){
    //     cout << strg[i] << " ";
    // }
    // cout << endl;

    return strg[strg.size() - 1];
}

int main(int argc, char** argv){
    int t;
    cin >> t;

    while(t--){
        int M, n, t;
        cin >> M;
        cin >> n;

        vector<int> x (n);
        vector<int> r (n);        
        
        for(int i = 0; i < n; i++){
            int val;
            cin >> val;
            x[i] = val;
        }


        for(int i = 0; i < n; i++){
            int val;
            cin >> val;
            r[i] = val;
        }

        cin >> t;

        // cout << billboard(x, r, M, t) << endl;  
        cout << highway(x, r, M, t) << endl;  
    }
}