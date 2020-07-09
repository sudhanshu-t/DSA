#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

string s = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
int getHashValue(string line){
    unordered_map<char, int> map;
    for(int i = 0; i < s.size(); i++){
        map[s[i]] = i;
    }

    // for(auto itr: map){
    //     cout << itr.first << " - " << itr.second << endl;
    // }

    vector<string> list;
    for(int i = 0; i < line.size(); i++){
        if(line[i] == ' '){
            string s1 = line.substr(0, i);
            list.push_back(s1);

            line = line.substr(i+1);
            i = -1;
        }
    }

    list.push_back(line);
    // for(int i = 0; i < list.size(); i++){
    //     cout << list[i] << " ";
    // }
    // cout << endl;

    int sum = 0;    
    
    for(int i = 0; i < list.size(); i++){
        for(int j = 0; j < list[i].size(); j++){
            sum += j + map[list[i][j]];
        }
    }

    // cout << sum << endl;

    if(sum == 66)
        return 2*sum;
    else
        return 4*sum;
}

int main(int argc, char** argv){
    string line;
    getline(cin, line);
    cout<<getHashValue(line);
}