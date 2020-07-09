#include <iostream>
#include <vector>

using namespace std;

int count_min(int n){
    vector<int> strg (n + 1, 0);

    for(int i = 1; i <= n; i++){
        if(i % 2 == 0 && i % 3 == 0){
            strg[i] = 1 + min(strg[i / 2], min(strg[i / 3], strg[i - 1]));
        } else if(i % 2 == 0){
            strg[i] = 1 + min(strg[i / 2], strg[i - 1]);
        } else if(i % 3 == 0){
            strg[i] = 1 + min(strg[i / 3], strg[i - 1]);
        } else {
            strg[i] = 1 + strg[i - 1];
        }
    }

    for(int i = 0; i <= n; i++){
        cout << strg[i] << " ";
    }
    cout << endl;

    return strg[n];
}

int main(int argc,char**argv){
    int n;
    cin>>n;
    cout<<count_min(n)<<endl;
}