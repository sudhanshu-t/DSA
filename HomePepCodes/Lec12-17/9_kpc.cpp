#include <iostream>
#include <vector>
#include <string>

using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};

vector<string> gkpc(string str){
    if(str.size() == 0){
        vector<string> br;
        br.push_back("");
        return br;
    }

    vector<string> r;

    string s = str.substr(1);
    r = gkpc(s);

    vector<string> mr;

    int idx = str[0] - '0';
    for(int i = 0; i < codes[idx].size(); i++){
        for(int j = 0; j < r.size(); j++){
            mr.push_back(codes[idx][i] + r[j]);
        }
    }

    return mr;
}

int main(int argc, char** argv){
    vector<string> kpc = gkpc("682");

    for(int i = 0; i < kpc.size(); i++){
        cout << kpc[i] << endl;
    }
}