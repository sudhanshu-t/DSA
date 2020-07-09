#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int maxlen(vector<int> &v,int n) {
    unordered_map<int, int> map;

    int presum = 0;
    int maxlen = 0;

    map[0] = -1;

    for(int i = 0; i < v.size(); i++){
        presum += v[i];

        if(map.find(presum) == map.end()){
            map[presum] = i;
        } else {
            int pot = i - map[presum];
            maxlen = max(maxlen, pot);
        }
    }

    return maxlen;  
}
    
int main(int argc,char** argv){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<maxlen(v,n)<<endl;
}