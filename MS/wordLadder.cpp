#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <unordered_set>

using namespace std;

bool noAns = false;

int ladder(vector<string>& dict, string start, string end, int lui, int lastMc){
    if(start == end){
        return 0;
    }
    
    string pot;
    int globalMc = INT_MIN;
    
    cout << start << " -> ";
    
    for(int i = 0; i < dict.size(); i++){
        bool onceFound = false;
        bool breaked = false;
        
        if(i == lui){
            continue;
        }
        
        for(int j = 0; j < dict[i].size(); j++){
            if(start[j] == dict[i][j]){
                continue;
            } else {
                if(onceFound == true){
                    breaked = true;
                    break;
                } else {
                    onceFound = true;
                }
            }
        }
        
        if(breaked == true){
            // More than one different character
            continue;
        }
        
        int mc = 0;
        for(int j = 0; j < dict[i].size(); j++){
            if(end[j] == dict[i][j]){
                mc++;
            }
        }
        
        if(mc > globalMc){
            globalMc = mc;
            
            pot = dict[i];
            lui = i;
        }
    }
    
    if(globalMc <= lastMc){
        noAns = true;
        return 0;  
    }
    
    int rres = ladder(dict, pot, end, lui, globalMc);
    return rres + 1;
}

class node{
public:
    string s;
    int mc;
    int steps;

    node(int m, int st, string str){
        s = str;
        steps = st;
        mc = m;
    }
};

int ladderLength(string start, string end, vector<string> &dictV) {
    queue<node> q;

    q.push(node (-1, 1, start));

    unordered_set<string> set;

    while(q.size() != 0){
        node front = q.front();
        q.pop();

        // cout << front.s << " -> ";

        if(front.mc == end.size() - 1){
            return front.steps + 1;
        }

        if(set.find(front.s) == set.end()){
            set.insert(front.s);
        } else {
            continue;
        }

        for(int i = 0; i < dictV.size(); i++){
            if(set.find(dictV[i]) != set.end()){
                continue;
            }

            bool onceFound = false;
            bool breaked = false;
            
            if(front.s == dictV[i]){
                continue;
            }
            
            for(int j = 0; j < dictV[i].size(); j++){
                if(front.s[j] == dictV[i][j]){
                    continue;
                } else {
                    if(onceFound == true){
                        breaked = true;
                        break;
                    } else {
                        onceFound = true;
                    }
                }
            }
            
            if(breaked == true){
                // More than one different character
                continue;
            }

            int mc = 0;
            for(int j = 0; j < dictV[i].size(); j++){
                if(end[j] == dictV[i][j]){
                    mc++;
                }
            }

            // cout << endl << "inserting" << endl;
            q.push(node(mc, front.steps + 1, dictV[i]));
        }
    }

    return 0;
}

int main(int argc, char** argv){
    vector<string> dict = {"baba", "abba", "aaba", "bbbb", "abaa", "abab", "aaab", "abba", "abba", "abba", "bbba", "aaab", "abaa", "baba", "baaa"};
    string start = "bbaa";
    string end = "babb";

    cout << "Answer: " << ladderLength(start, end, dict) << endl;
}