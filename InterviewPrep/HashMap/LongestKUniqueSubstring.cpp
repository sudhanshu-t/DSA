#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

void print(string &str, int k) {
    unordered_map<char, int> map;

    int i = -1, j = 0;
    int maxlen = 0;

    while(j < str.size()){
        map[str[j]]++;
        j++;


        if(map.size() > k || j == str.size()){
            maxlen = (j == str.size() && map.size() == k) ? max(maxlen, j - 1 - i) : max(maxlen, j - 2 - i);
        }

        while(map.size() > k){
            i++;
            map[str[i]]--;

            if(map[str[i]] == 0){
                map.erase(str[i]);
            }
        }
    }

    cout << maxlen << endl;
}

int main(int argc,char** argv){
    string s;
    cin>>s;
    int k;
    cin>>k;
    print(s,k);
}