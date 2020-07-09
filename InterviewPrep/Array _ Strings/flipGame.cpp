#include<iostream>
#include<vector>
// #include<string>
using namespace std;

vector<string> generatePossibleNextMoves(string &s) {
    vector<string> res;

    int i = 0;
    while(i < s.size() - 1){
        if(s[i] == '+' && s[i+1] == '+'){
            s[i] = '-';
            s[i+1] = '-';
            res.push_back(s);
            s[i] = '+';
            s[i+1] = '+';
        }

        i++;
    }

    return res;
}

int main(int argc, char** argv){
    string s;
    cin>>s;
    vector<string> res = generatePossibleNextMoves(s);
    cout<<"[";
    for(int i=0; i<res.size(); i++){
        cout<<res[i];
        if(i != res.size() - 1){
            cout<<", ";
        }
    }
    cout<<"]";
}