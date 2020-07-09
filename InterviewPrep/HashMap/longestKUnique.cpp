#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

void longestK(string s, int k){
    unordered_map<char, int> fmap;
    
    int count = 0;
    int i = -1; int j = 0;

    // Acquire*
    while(j < s.size()){
        fmap[s[j]]++;

        if(fmap.size() > k){
            // Settle
            count = max(count, j - 1 - i);

            // Release*
            while(fmap.size() != k){
                i++;
                fmap[s[i]]--;

                if(fmap[s[i]] == 0){
                    fmap.erase(s[i]);
                }
            }
        }

        j++;
    }

    cout << count << endl;
}

int main(int argc, char** argv){
    longestK("aabacbebebe", 3);
}