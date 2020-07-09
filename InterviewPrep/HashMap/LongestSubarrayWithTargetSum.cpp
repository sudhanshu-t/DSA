#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits.h>

using namespace std;

void print (vector<int> &v,int k,int n) {
    //Write your code here     
    unordered_map<int, int> fmap;
    int presum = 0;
    int maxlen = 0;

    fmap[0] = -1;

    for(int i = 0; i < v.size(); i++){
        presum += v[i];

        if(fmap.find(presum) == fmap.end()){
            fmap[presum] = i;
        }

        if(fmap.find(presum - k) != fmap.end()){
            int pot = i - fmap[presum - k];
            maxlen = max(maxlen, pot);
        }
    }

    cout << maxlen << endl;
}
    
int main(int argc,char** argv){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    print(v,k,n);
}