#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

// abbcdaddbadcdbcaa
// ddccba

using namespace std;
vector<int> findAnagrams(string& s,string& p){
    unordered_map<char, int> act;
    unordered_map<char, int> curr;
    
    for(int i = 0; i < p.size(); i++){
        act[p[i]]++;
    }

    int i = -1; int j = 0;
    vector<int> res;

    int mc = 0;
    while(j < s.size()){
        // Acquire
        if(act.find(s[j]) != act.end() && curr[s[j]] < act[s[j]]){
            curr[s[j]]++;
            mc++;

            // cout << mc << endl;

            // Release
            while(mc == p.size()){
                i++;
                if(curr[s[i]] <= act[s[i]]){
                    mc--;
                }

                curr[s[i]]--;

                // cout << mc << endl;
                // cout << "Length " << j - i + 1 << endl;

                if(mc < p.size() && j - i + 1 == p.size()){
                    // cout << mc << endl;
                    // cout << "Length " << j - i + 1 << endl;

                    res.push_back(i);
                }
            }
        }
        else {
            curr[s[j]]++;
        }
        j++;
    }

    return res;
}

int main(int argc,char** argv){
    string s;
    string p;
    getline(cin,s);
    getline(cin,p);
    vector<int> v; 
    v=findAnagrams(s,p);
    cout<<"[";
    int i=0;
    for(i=0;i<v.size();i++){
        cout<<v[i];
        if(i!=v.size()-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;

}