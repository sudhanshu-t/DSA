#include <iostream>
#include <vector>
#include <string>

using namespace std;

void mindeletions(string& str){
    vector<vector<int>> strg(str.size(), vector<int> (str.size(), 0));

    for(int x = 0; x < str.size(); x++){
        for(int i = 0, j = x; j < str.size(); i++, j++){
            if(x == 0){
                strg[i][j] = 1;
                continue;
            }
            
            if(str[i] == str[j]){
                strg[i][j] = 2 + strg[i+1][j-1];
            } else {
                strg[i][j] = max(strg[i+1][j], strg[i][j-1]);
            }
        }
    }
    
    cout << str.size() - strg[0][strg[0].size() - 1] << endl;
}

int main(int argc,char**argv){
    string s;
    getline(cin,s);
    mindeletions(s);
}