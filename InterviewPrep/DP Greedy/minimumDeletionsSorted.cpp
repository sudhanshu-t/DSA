#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void mindeletions(vector<int>& a, int n)
{
    int globalMax = 0;
    vector<int> strg (n);
    strg[0] = 1;
    for(int i = 1; i < a.size(); i++){
        int myMax = 0;
        for(int j = 0; j < i; j++){
            if(a[j] <= a[i]){
                myMax = max(myMax, strg[j]);
            }
        }

        strg[i] = myMax + 1;
        globalMax = max(globalMax, strg[i]);
    }

    cout << a.size() - globalMax << endl;
}
int main(int argc,char**argv){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }   

    mindeletions(v,n);
}