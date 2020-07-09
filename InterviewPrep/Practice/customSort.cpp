#include <bits/stdc++.h>
using namespace std;

vector<int> prio;

static bool comptor(char& a, char& b) {
    return prio[a - 'a'] < prio[b - 'a'];
}

string customSortString(string S, string T) {
    int p = 0;
    prio.resize(26);
    
    for (int i = 0; i < S.size(); i++) {
        prio[S[i] - 'a'] = p++;
    }   
    
    sort(T.begin(), T.end(), comptor);
    
    return T;
}

int main() {
    string s = "cba";
    string t = "bbaacccadddccbbaa";

    cout << customSortString(s, t) << endl;
}