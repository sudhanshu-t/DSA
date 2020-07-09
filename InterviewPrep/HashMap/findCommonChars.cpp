#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;


//this is a functional problem
vector<string> commonChars(vector<string>& A){
    //write your code here
    vector<string> ans;

    int count[26];
    for(int i = 0; i < 26; i++)
        count[i] = INT_MAX;

    for(string s : A){
        int temp[26] = {0};
        for(int i = 0; i < s.size(); i++){
            temp[s[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            count[i] = min(count[i], temp[i]);
        }
    }

    for(int i = 0; i < 26; i++){
        if(count[i] > 0){
            while(count[i] > 0){
                char c = (char)('a' + i);
                string s (1, c);
                ans.push_back(s);
                count[i]--;
            }
        }
    }

    return ans;
}

void display(vector<string> &ans){
    cout<<"[";
        for(int j=0;j<ans.size();j++){
            cout<<ans[j];
            if(j!=ans.size()-1){
                cout<<", ";
            }            
        }
    cout<<"]"<<endl;
}
int main(int argc,char ** argv){

    int n;
    cin>>n;
    vector<string> A;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        A.push_back(a);
    }
    vector<string> res;
    res=commonChars(A);
    sort(res.begin(),res.end());
    display(res);

    // int i = 11;
    // cout << char('a' + i) << endl;

}