#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring (string &s) {
    unordered_set<char> set;

    int maxlen = 0;
    int i = -1, j = 0;

    while(j < s.size()){
        // acquire till no duplicacy
        while(j < s.size() && set.find(s[j]) == set.end()){
            set.insert(s[j]);
            j++;
        }

        int pot = j - 1 - i;
        maxlen = max(maxlen, pot);

        // release till no duplicacy
        while(j < s.size() && set.find(s[j]) != set.end()){
            i++;
            set.erase(s[i]);
        }
    }

    return maxlen;
}
    
int main(int argc,char** argv){
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s)<<endl;
}