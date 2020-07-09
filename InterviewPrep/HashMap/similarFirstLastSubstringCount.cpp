#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
int count(string s) {
    //Write your code here
    unordered_map<char, int> map;

    int i = 0;
    int count = 0;

    while(i < s.size()){
        count++;
        if(map.find(s[i]) == map.end()){
            map[s[i]]++;
        } else {
            count += map[s[i]];
            map[s[i]]++;
        }
        i++;
    }

    return count;
}

//Don't write your code here
int main(int argc, char** argv){
    string str;
    cin>>str;
    int ans = count(str);
    cout<<ans;
}