#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

bool canConstruct(string & rans, string& magzine) {
    unordered_map<char, int> map_ran;
    unordered_map<char, int> map_mag;

    for(int i = 0; i < rans.size(); i++){
        map_ran[rans[i]]++;
    }

    for(int i = 0; i < magzine.size(); i++){
        map_mag[magzine[i]]++;
    }

    for(auto itr : map_ran){
        if(map_mag.find(itr.first) == map_mag.end() || 
          (map_mag.find(itr.first) != map_mag.end() && itr.second > map_mag[itr.first])){
              return false;
          }
    }

    return true;
}

int main (int argc,char** argv){
    string s,t;
    cin>>s;
    cin>>t;
    bool res=canConstruct(s,t);
    if(res==true){
        cout<<"true";
    }else{
        cout<<"false";
    }

}