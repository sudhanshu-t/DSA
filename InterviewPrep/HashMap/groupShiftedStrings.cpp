#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
// This is a functional problem. You have to complete this function.
// It takes as input the a string array. It return a list of list of
// strings of strings with same shifting sequence grouped together.

string stringToNum(string s){
    if(s.size() == 1){
        string str = to_string(0);
        return str;
    }
    
    string ans;
    for(int i = 0; i < s.size() - 1; i++){
        char c1 = s[i];
        char c2 = s[i+1];

        int i1 = c1 - 'a';
        int i2 = c2 - 'a';

        int val = (i2 >= i1) ? i2 - i1 : (26 + (i2 - i1));
        ans += to_string(val) + ".";
    }

    return ans;
}

vector<vector<string>> groupStrings(vector <string>& strs){
    // write your code here.
    unordered_map<string, vector<string>> map;
    
    for(int i = 0; i < strs.size(); i++){
        string s = stringToNum(strs[i]);

        if(map.find(s) == map.end()){
            vector<string> v;
            v.push_back(strs[i]);
            map[s] = v;
        } else {
            map[s].push_back(strs[i]);
        }
    }

    vector<vector<string>> ans;

    for(auto itr : map){
        vector<string> temp;
        temp = itr.second;
        sort(temp.begin(), temp.end());
        ans.push_back(temp);
    }

    return ans;
}

void display(vector<vector<string> > &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
//function to sort the lists
bool sortcol( const vector<string>& l1, 
            const vector<string>& l2 ) { 

    if (l1.size() != l2.size()) {
        return l2.size()<l1.size();
    } else {
        if(l1.size()==0){
            return false;
        }else{
            return l1[0]<l2[0];
        }
    }

} 
int main(int argc,char ** argv){

    int n;
    cin>>n;
    vector<string> strs;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        strs.push_back(a);
    }
    
    vector<vector<string> > res;
    res=groupStrings(strs);
    for(vector<string> v:res){
        sort(v.begin(),v.end());
    }
    sort(res.begin(),res.end(),sortcol);
    display(res);

    // cout << 'c' - 'a' << endl;

    // cout << stringToNum("az") << endl;
    // cout << stringToNum("ba") << endl;
    // cout << stringToNum("cb") << endl;
    // cout << stringToNum("aa") << endl;

}