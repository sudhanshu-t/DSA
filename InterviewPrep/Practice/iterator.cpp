#include <bits/stdc++.h>
using namespace std;

class CombinationIterator {
    vector<string> all;
    int idx;
    
    vector<string> getAll(string s, int k) {
        if (s.size() < k) {
            vector<string> bres;
            return bres;
        }
        
        if (k == 1) {
            vector<string> bres;
            for (int i = 0; i < s.size(); i++) {
                string str(1, s[i]);
                bres.push_back(str);
            }
            
            return bres;
        }
        
        vector<string> mres;
        for (int i = 0; i < s.size(); i++) {
            vector<string> rres = getAll(s.substr(i + 1), k - 1);
            for (int j = 0; j < rres.size(); j++) {
                mres.push_back(s[i] + rres[j]);
            }
        }
        
        return mres;
    }
    
public:
    CombinationIterator(string s, int k) {
        idx = 0;
        all = getAll(s, k);

        for (string str: all) cout << str << " ";
        cout << endl;
    }
    
    string next() {
        if (idx < all.size())
            return all[idx++];
        return "";
    }
    
    bool hasNext() {
        if (idx == all.size()) return false;
        return true;
    }
};

int main() {
    CombinationIterator* obj = new CombinationIterator("abcde", 3);
    while (obj->hasNext())
        cout << obj->next() << endl;
}