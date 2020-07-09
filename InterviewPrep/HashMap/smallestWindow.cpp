#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <climits>

using namespace std;

void smallestWin(string s, string pat){
    unordered_set<char> set;
    for(int i = 0; i < pat.size(); i++){
        set.insert(pat[i]);
    }

    unordered_map<char, int> map;
    
    int i = -1, j = 0;
    int len = INT_MAX;
    int start = 0;

    while(j < s.size()){
        if(set.find(s[j]) != set.end()){
            map[s[j]]++;

            if(map.size() == set.size()){
                int temp = j - i;
                if(temp < len){
                    len = temp;
                    start = i+1;
                } else if(temp == len){
                    if(i+1 < start){
                        start = i+1;
                    }
                }
                // cout << "j " << len << " " << start << endl; 
            }


            while(map.size() == set.size()){
                i++;
                if(map.find(s[i]) != map.end()){
                    map[s[i]]--;

                    if(map[s[i]] == 0){
                        map.erase(s[i]);

                        int temp = j - i + 1;
                        if(temp < len){
                            len = temp;
                            start = i;
                        } else if(temp == len){
                            if(i < start){
                                start = i;
                            }
                        }

                        // cout << "i " << len << " " << start << endl; 

                        break;
                    }
                }
            }
        }

        j++;
    }

    if(len != INT_MAX){
        // cout << len << endl;
        cout << s.substr(start, len);
    } else {
        cout << "-1";
    }
}

int main(int argc, char** argv){
    string s, pat;
    cin >> s >> pat;

    smallestWin(s, pat);
}