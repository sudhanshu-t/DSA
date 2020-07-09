#include <iostream>
#include <vector>
#include <string>

using namespace std;

string codes[] = {";.", "abc", "def", "ghi", "jkl", "mno", "pqrs", "uv", "wx", "yz"};

vector<string>* get_kpc(string s, int idx){
    if(idx == s.size()){
        vector<string>* bres = new vector<string>;
        bres->push_back("");

        return bres;
    }
    
    vector<string>* rres = get_kpc(s, idx + 1);

    vector<string>* mres = new vector<string>;

    string small_s = codes[s[idx] - '0'];
    // cout << small_s << endl;

    for(int i = 0; i < small_s.size(); i++){
        for(int j = 0; j < rres->size(); j++){
            mres->push_back(small_s[i] + rres->at(j));
        }
    }

    return mres;
}

int main(int argc, char** argv){
    vector<string>* v = get_kpc("682", 0);

    for(int i = 0; i < v->size(); i++){
        cout << (*v)[i] << endl;
    }

    cout << endl << v->size() << endl;

    return 0;
}