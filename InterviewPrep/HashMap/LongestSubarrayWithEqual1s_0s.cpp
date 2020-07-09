#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
void print (vector<char> &v) {
    unordered_map<int, int> map;
    vector<int> vint (v.size(), 1);

    int presum = 0;
    int maxlen = 0;

    for(int i = 0; i < v.size(); i++){
        if(v[i] - '0' == 0) vint[i] = -1;
    }

    for(int i = 0; i < vint.size(); i++){
        cout << vint[i] << " ";
    }
    cout << endl;

    map[0] = -1;

    for(int i = 0; i < vint.size(); i++){
        presum += vint[i];

        if(map.find(presum) == map.end()){
            map[presum] = i;
        } else {
            int pot = i - map[presum];
            maxlen = max(maxlen, pot);
        }
    }

    for(auto itr : map){
        cout << itr.first << " " << itr.second << endl;
    }

    cout << maxlen << endl;
}
    
int main(int argc,char** argv){
    string s;
    cin>>s;
    vector<char> v(s.length());
    for(int i=0;i<s.length();i++){
        v[i]=s[i];
    }
    print(v);
}