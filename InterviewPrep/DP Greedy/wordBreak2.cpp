#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<string>* wordBreak2(unordered_set<string>& set, string sent){
    if(sent.size() == 0){
        // cout << "size == 0" << endl;
        vector<string>* bres = new vector<string>();
        
        bres->push_back("");
        return bres;
    }
    
    vector<string>* mres = new vector<string>();
    for(int i = 1; i <= sent.size(); i++){
        string s = sent.substr(0, i);
        string rw = sent.substr(i);
        // cout << s << " " << rw << endl;
 
        if(set.find(s) != set.end()){
            vector<string>* rres = wordBreak2(set, rw);
            
            for(int j = 0; j < (*rres).size(); j++){
                if((*rres)[j] != ""){
                    (*rres)[j] = s + " " + (*rres)[j];    
                    // cout << (*rres)[j] << " if" << endl;
                } else {
                    (*rres)[j] = s;
                    // cout << (*rres)[j] << " else" << endl;
                }
                
                mres->push_back((*rres)[j]);
            }
        }
    }

    // cout << endl << "Mres -> ";
    // for(int i = 0; i < mres->size(); i++){
    //     cout << mres->at(i) << " ";
    // }
    // cout << endl;
    
    return mres;
}

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    
	    unordered_set<string> set;
	    
	    for(int i = 0; i < n; i++){
	        string x;
	        cin >> x;
	        
	        set.insert(x);
	    }
	    
	    string sent;
	    cin >> sent;
	    
	    vector<string>* res = wordBreak2(set, sent);
	    
	    if(res->size() == 0){
	        cout << "Empty" << endl;
	    } else {
	        for(int i = 0; i < res->size(); i++){
	            cout << "(" << (*res)[i] << ")";
	        }
	        cout << endl;
	    }
	}
	return 0;
}

// vector<string> wordBreak2(unordered_set<string>& set, string sent){
//     vector<string> res;
    
//     vector<int> strg (sent.size(), 0);
//     string first (1, sent[0]);
//     strg[0] = (set.find(first) != set.end()) ? 1 : 0;
    
//     if(strg[0] == 1){
//         res.push_back(first + " ");
//     }
    
//     for(int i = 1; i < strg.size(); i++){
//         for(int j = 0; j < i; j++){
//             if(strg[j] == 1){
//                 string str = sent.substr(j+1, i - j);
                
//                 if(set.find(str) != set.end()){
//                     strg[i] = 1;
                    
//                     for(int i = 0; i < res.size(); i++){
//                         if(res[i][res[i].size() - 2] == sent[j] && ){
//                             res[i] += str + " ";
//                             cout << res[i] << endl;
//                         }
//                     }
//                 }
//             }
//         }
        
//         if(strg[i] == 0){
//             string str = sent.substr(0, i+1);
//             if(set.find(str) != set.end()){
//                 strg[i] = 1;
//                 res.push_back(str + " ");
//             }
//         }
//     }
    
//     return res;
// }



// int main() {
// 	int t;
// 	cin >> t;
	
// 	while(t--){
// 	    int n;
// 	    cin >> n;
	    
// 	    unordered_set<string> set;
	    
// 	    for(int i = 0; i < n; i++){
// 	        string x;
// 	        cin >> x;
	        
// 	        set.insert(x);
// 	    }
	    
// 	    string sent;
// 	    cin >> sent;
	    
// 	    vector<string> res = wordBreak2(set, sent);
	    
// 	    if(res.size() == 0){
// 	        cout << "Empty" << endl;
// 	    } else {
// 	        for(int i = 0; i < res.size(); i++){
// 	            cout << "(" << res[i] << ")";
// 	        }
// 	        cout << endl;
// 	    }
// 	}
// 	return 0;
// }