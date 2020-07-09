#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
int consecuitveSub(vector<int> &v,int n) {
    unordered_map<int, bool> map;

    for(int i = 0; i < v.size(); i++){
        map[v[i]] = true;
    }

    for(int i = 0; i < v.size(); i++){
        if(map.find(v[i] - 1) != map.end()){
            map[v[i]] = false;
        }
    }

    int ol = 0;
    int os = 0;
    for(auto itr : map){
        if(itr.second == true){
            int tl = 1;
            int ts = itr.first;

            while(map.find(itr.first + tl) != map.end()){
                tl++;
            }

            if(tl > ol){
                ol = tl;
                os = ts;
            }
        }
    }

    return ol;
}
    
int main(int argc,char** argv){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<consecuitveSub(v,n)<<endl;
}