#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void print(vector<int>& v, int k, int n) {
    int maxlen = 0;
    int presum = 0;
    unordered_map<int, int> map;

    map[0] = -1;
    for(int i = 0; i < v.size(); i++){
        presum += v[i];

        if(map.find(presum % k) != map.end()){
            int pot = i - map[presum % k];
            maxlen = max(maxlen, pot);
        } else {
            map[presum % k] = i;
        }
    }
    
    cout << maxlen << endl;
}
    
int main(int argc,char** argv){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int k;
    cin>>k;
    print(v,k,n);
}