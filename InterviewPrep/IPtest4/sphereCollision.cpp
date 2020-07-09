#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int dotProduct(vector<int>& a, vector<int>& b){
    int ans = 0;
    
    ans += a[0]*b[0] +
           a[1]*b[1] +
           a[2]*b[2];
    
    return ans;
}

bool willCollide(int r1, int r2, vector<int>& p1, vector<int>& a1, vector<int>& p2, vector<int>& a2){
    vector<int> p (3);
    
    p[0] = p1[0] - p2[0];
    p[1] = p1[1] - p2[1];
    p[2] = p1[2] - p2[2];
    
    vector<int> v (3);
    
    v[0] = a1[0] - a2[0];
    v[1] = a1[1] - a2[1];
    v[2] = a1[2] - a2[2];

    int dot1 = dotProduct(p, v);
    int dot2 = dotProduct(v, v);

    int t = 0;
    if(dot2 != 0){
        double d = (dot1 * 1.0) / dot2;
        d = (-1)*d;
        cout << "d - " << d << endl;
        t = max(d, 0.0);
    }

    cout << t << endl;

    vector<int> ansVec (3);
    ansVec[0] = p[0] + v[0]*t;
    ansVec[1] = p[1] + v[1]*t;
    ansVec[2] = p[2] + v[2]*t;
    
    int ans = dotProduct(ansVec, ansVec);
    
    if(ans <= r1*r1 + r2*r2){
        return true;
    }
    
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    
    while(t--){
        int r1, r2;
        cin >> r1 >> r2;
        
        vector<int> p1(3);
        vector<int> a1(3);
        vector<int> p2(3);
        vector<int> a2(3);
        
        cin >> p1[0];
        cin >> p1[1];
        cin >> p1[2];
        
        cin >> a1[0];
        cin >> a1[1];
        cin >> a1[2];
        
        cin >> p2[0];
        cin >> p2[1];
        cin >> p2[2];
        
        cin >> a2[0];
        cin >> a2[1];
        cin >> a2[2];
        
        bool ans = willCollide(r1, r2, p1, a1, p2, a2);
        
        if(ans){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
