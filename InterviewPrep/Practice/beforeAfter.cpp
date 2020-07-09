#include <bits/stdc++.h>
using namespace std;

string getFirstWord(string s){
    int i = 0;
    while(i < s.size() && s[i] != ' '){
        i++;
    }

    if(i == s.size()){
        return s;
    }

    return s.substr(0, i);
}

string getLastWord(string s){
    int i = s.size()-1;
    while(i >= 0 && s[i] != ' '){
        i--;
    }

    if(i < 0){
        return s;
    }

    return s.substr(i+1);
}

string merge(string front, string back, int size){
    front += back.substr(size);
    return front;
}

vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
    unordered_set<string> set;
    vector<string> res;
    multimap<string, pair<string, string>> map;
    for(int i = 0; i < phrases.size(); i++){
        string fw = getFirstWord(phrases[i]);
        string lw = getLastWord(phrases[i]);
        map.insert(pair <string, pair<string, string>> (phrases[i], make_pair(fw, lw)));;
    }
    
    for(auto i: map){
        cout << i.first << " -> " << i.second.first << " & " << i.second.second << endl;
    }
    
    for(auto &&i: map){
        for(auto &&j: map){
            if(&i != &j){
                if(i.second.first == j.second.second){
                    string s = merge(j.first, i.first, i.second.first.size());
                    set.insert(s);
                }
                // if(i.second.second == j.second.first){
                //     string s = merge(i.first, j.first, i.second.second.size());
                //     res.push_back(s);
                // }
            }
        }
    }

    for(auto itr: set){
        res.push_back(itr);
    }

    sort(res.begin(), res.end());
    return res;
}

int main(){
    vector<string> phrases = {"mission statement",
                  "a quick bite to eat",
                  "a chip off the old block",
                  "chocolate bar",
                  "mission impossible",
                  "a man on a mission",
                  "block party",
                  "eat my words",
                  "bar of soap"};
    // vector<string> phrases = {"a","b","a"};

    vector<string> res = beforeAndAfterPuzzles(phrases);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
}