#include<iostream>
#include<unordered_map>

using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input the String s ant t. It should return true if t is
// and anagram of s, else should return false.
bool isAnagram(string s, string t) {
    // write your code here.
    if(s.size() != t.size()){
        return false;
    }
    
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

    if(map.size() != 0){
        return false;
    }

    return true;
}

int main(int argc, char** argv){
    string s, t;
    cin>>s>>t;

    if (isAnagram(s, t)) {
        cout<<"Yes";
    } else {
        cout<<"No";
    }
}