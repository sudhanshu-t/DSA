#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int longestPalindrome(string &str) {
    //Write your code here	 	 
    unordered_map<char, int> map;

    for(int i = 0; i < str.size(); i++){
        map[str[i]]++;
    }

    int maxlen = 0;
    for(auto itr : map){
        if(itr.second % 2 == 0){
            maxlen += itr.second;
        } else {
            maxlen += itr.second - 1;
        }
    }

    return maxlen + 1;
}

int main(int argc,char** argv){
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;
}