#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input 2 strings
// It should return a boolean value

bool wordPattern(string &pattern, string &str) {    
    unordered_map<char, string> map;

    vector<string> words;

    int i;
    for(i = 0; i < str.size(); i++){
        if(str[i] == ' '){
            string s = str.substr(0, i);
            words.push_back(s);
            str = str.substr(i+1);

            i = 0;
        }
    }

    words.push_back(str);

    unordered_map<string, char> wmap;

    for(int i = 0; i < words.size(); i++){
        if(wmap.find(words[i]) == wmap.end()){
            wmap[words[i]] = pattern[i];
        } else {
            if(wmap[words[i]] != pattern[i]){
                return false;
            }
        }
    }

    for(int i = 0; i < pattern.size(); i++){
        if(map.find(pattern[i]) == map.end()){
            map[pattern[i]] = words[i];
        } else {
            if(map[pattern[i]] != words[i]){
                return false;
            }
        }
    }

    return true;
}


int main(int argc, char** argv){
    string pattern, str;
    getline(cin, pattern);
    getline(cin, str);

    if(wordPattern(pattern,str)){
        cout<<"true";
    }else{
        cout<<"false";
    }
}