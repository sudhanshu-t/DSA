#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int i = -1, j = 0, len = 0;

    unordered_set<char> set;
    string ls;

    while(j < s.size()){
        char c = s[j];

        if(set.find(c) == set.end()){
            set.insert(c);

            // cout << j - i << endl;
            len = max(len, j - i);
            
            ls = s.substr(i+1, j - i);
            // cout << i+1 << " -> " << ls << endl;
        } else {
            while(set.find(c) != set.end()){
                i++;
                set.erase(s[i]);
            }

            continue;
        }

        j++;
    }


    return len;
}

int main(){
    string s = "";

    // int i = 3, j = 7;

    // string ls = s.substr(1, 3);
    // cout << ls << endl;

    cout << lengthOfLongestSubstring(s) << endl;
}