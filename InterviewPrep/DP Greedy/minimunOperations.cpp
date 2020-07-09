#include <iostream>
#include <vector>
using namespace std;

void minOperations(int n){
    vector<int> strg(n + 1, 0);

    for(int i = 1; i <= n; i++){
        if(i % 2 == 0){
            strg[i] = 1 + min(strg[i / 2], strg[i - 1]);
        } else {
            strg[i] = 1 + strg[i - 1];
        }
    }

    cout << strg[n] << endl;
}

int main(int argc,char**argv){
    int n;
    cin>>n;
    minOperations(n);
}