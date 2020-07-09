#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input the String s ant t. It should return the different
// character.
char findTheDifference(string& s, string& t) {
    // write your code here.
    
    unordered_map<char, int> map;
    for(int i = 0; i < t.size(); i++){
        map[t[i]]++;
    }

    for(int i = 0; i < s.size(); i++){
        if(map.find(s[i]) != map.end()){
            map[s[i]]--;

            if(map[s[i]] == 0){
                map.erase(s[i]);
            }
        }
    }

    for(auto itr : map){
        return itr.first;
    }
}
//Don't make any changes here

int main(int argc,char** argv){

    string s,t;
    cin>>s;
    cin>>t;
    cout<<findTheDifference(s,t)<<endl;
}