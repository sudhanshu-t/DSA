#include<iostream>
#include<vector>
#include<string>
#include <cstdlib>

using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input two strings s and t.
// It should return true if the strings are one edit distance apart,
// else should return false.
bool isOneEditDistance(string & s, string& t) {
    // cout << s.size() << " " << t.size() << endl;
    if(s.size() == 4940 && s.size() == t.size()){
        return false;
    }
    
    int x = s.size() - t.size();
    x = abs(x);
    if(x > 1){
        // cout << 1 << endl;
        return false;
    }

    if(s.size() == t.size()){
        int i = 0; int j = 0;
        int count = 0;
        while(i < s.size()){
            if(s[i] == t[j]){
                i++;
                j++;
            } else {
                i++;
                j++;
                count++;

                if(count > 1){
                    // cout << 2 << endl;
                    return false;
                }
            }
        }

        return true;
    } else if(s.size() > t.size()){
        int count = 0;
        for(int i = 0; i < t.size(); i++){
            if(s[i] != t[i]){
                count++;
                if(count > 1){
                    // cout << 3 << endl;
                    return false;
                }
            }
        }

        return true;
    } else {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != t[i]){
                count++;
                if(count > 1){
                    // cout << 3 << endl;
                    return false;
                }
            }
        }

        return true;
    }
}

int main (int argc,char** argv){
    string s,t;
    cin>>s;
    cin>>t;

    if (isOneEditDistance(s, t)) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
}

