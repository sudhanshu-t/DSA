#include <bits/stdc++.h>
using namespace std;

pair<int, int> getAns(vector<pair<string, string>>& input){
    int sleep = 0;
    int wake = 0;
    for(int i = 0; i < input.size(); i++){
        string s = input[i].first;
        string e = input[i].second;
        int st = stoi(s.substr(0, 2))*60 + stoi(s.substr(3,2));
        int end = stoi(e.substr(0, 2))*60 + stoi(e.substr(3,2));
        if(end-st < 0){
            end += 1440;
        }
        sleep += end - st;
        
        if(i+1 < input.size()){
            s = input[i+1].first;
            st = stoi(s.substr(0, 2))*60 + stoi(s.substr(3,2));
            
            if(st-end < 0){
                st += 1440;
            }
            wake += st - end;
        }

    }

    pair<int, int> ans = make_pair(wake, sleep);
    return ans;
}

int main(){
    string str;
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        getline(cin, str);
        int n;
        cin >> n;
        vector<pair<string, string>> input (n);
        for(int i = 0; i < n; i++){
            cin >> input[i].first;
            cin >> input[i].second;
        }

        pair<int, int> ans = getAns(input);
        cout << "Case #" << i << " " << ans.first << " " << ans.second << endl;
    }

    return 0;
}