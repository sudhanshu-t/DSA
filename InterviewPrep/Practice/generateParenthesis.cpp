#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

vector<string> generateParenthesis(int n) {
    vector<string> res;
    if(n == 0){
        res.push_back("");
        return res;
    }
    
    if(n == 1){
        res.push_back("()");
        return res;
    }
    
    unordered_set<string> set;
    
    for(int i = 0; i < n; i++){
        vector<string> rres1 = generateParenthesis(i);
        vector<string> rres2 = generateParenthesis(n-i-1);
        
        for(int j = 0; j < rres1.size(); j++){
            for(int k = 0; k < rres2.size(); k++){
                string s = rres1[j] + rres2[k];
                
                string pot1 = s + "()";
                string pot2 = "(" + s + ")";
                string pot3 = "()" + s;
                
                if(set.find(pot1) == set.end()){
                    set.insert(pot1);
                    res.push_back(pot1);
                }

                if(set.find(pot2) == set.end()){
                    set.insert(pot2);
                    res.push_back(pot2);
                }

                if(set.find(pot3) == set.end()){
                    set.insert(pot3);
                    res.push_back(pot3);
                }
            }
        }
    }
    
    return res;
}

int main(){
    vector<string> res = generateParenthesis(5);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
}