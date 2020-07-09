#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class DSU{
public:
    vector<int> parent;
    vector<int> rank;

    DSU (int size){
        parent.resize(size);
        rank.resize(size);

        for(int i = 0; i < parent.size(); i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool performUnion(int x, int y){
        int xP = find(x);
        int yP = find(y);
        if(xP == yP){
            return false;
        } else if (rank[xP] > rank[yP]){
            parent[yP] = xP;
        } else if (rank[yP] > rank[xP]){
            parent[xP] = yP;
        } else {
            parent[yP] = xP;
            rank[xP]++;
        }
        return true;
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, string> person;
    unordered_map<string, int> indices;
    int index = 0;
    for(int i = 0; i < accounts.size(); i++){
        for(int j = 1; j < accounts[i].size(); j++){
            string s = accounts[i][j];
            if(indices.find(s) == indices.end()){
                indices[s] = index++;
            }
            person[s] = accounts[i][0];
        }
    }

    int size = indices.size();
    DSU dsu(size);
    for(int i = 0; i < accounts.size(); i++){
        if(accounts[i].size() > 2){
            for(int j = 1; j < accounts[i].size()-1; j++){
                string x = accounts[i][j];
                string y = accounts[i][j+1];
                bool merged = dsu.performUnion(indices[x], indices[y]);
            }
        }
    }

    // for(auto i: indices){
    //     cout << i.first << " -> " << dsu.parent[indices[i.first]] << " with rank " << dsu.rank[indices[i.first]] << endl;
    // }

    vector<vector<string>> res;
    for(auto itr: indices){
        string s = itr.first;
        if(dsu.find(indices[s]) == indices[s]){
            vector<string> temp;
            temp.push_back(person[s]);
            for(auto i: indices){
                if(indices[s] == dsu.find(indices[i.first])){
                    temp.push_back(i.first);
                }
            }
            res.push_back(temp);
        }
    }

    for(int i = 0; i < res.size(); i++){
        partial_sort(res[i].begin()+1, res[i].begin() + res[i].size() - 1, res[i].end());
    }

    return res;
}

int main(){
    vector<vector<string>> input = {
        {"John", "js", "j00"},
        {"John", "jbr", "jf"},
        {"John", "j00", "jf"},
        {"John", "js", "js", "jnw"},
        {"John", "jss"},
        {"John", "jss", "jst"}
    };

    vector<vector<string>> res = accountsMerge(input);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

// vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
//     unordered_map<string, int> indices;
//     vector<vector<string>> res;
//     // res.resize(1001);
//     // int maxSize = 1000;

//     // DSU dsu (maxSize);

//     int index = 0;

//     for(int i = 0; i < accounts.size(); i++){
//         string person = accounts[i][0];
//         string identifier;
//         bool idExists = false;

//         int curr;
//         for(int j = 1; j < accounts[i].size(); j++){
//             string s = accounts[i][j];

//             if(indices.find(s) == indices.end()){
//                 continue;
//             } else {
//                 idExists = true;
//                 curr = indices[s];
//                 break;
//             }
//         }

//         if(!idExists){
//             for(int j = 1; j < accounts[i].size(); j++){
//                 if(indices.find(accounts[i][j]) == indices.end()){
//                     indices[accounts[i][j]] = index;
//                 } else {
//                     accounts[i].erase(accounts[i].begin() + j);
//                 }
//             }

//             curr = index++;
//         }

//         if(!idExists){
//             vector<string> temp;
//             temp.push_back(accounts[i][0]);
//             for(int j = 1; j < accounts[i].size(); j++){
//                 temp.push_back(accounts[i][j]);
//             }
//             res.push_back(temp);
//         } else {
//             for(int j = 1; j < accounts[i].size(); j++){
//                 if(indices.find(accounts[i][j]) != indices.end()){
//                     continue;
//                 }
//                 res[curr].push_back(accounts[i][j]);
//                 indices[accounts[i][j]] = curr;
//             }
//         }
//     }

//     // cout << 1 << endl;
//     for(int i = 0; i < res.size(); i++){

//         partial_sort(res[i].begin()+1, res[i].begin() + res[i].size() - 1, res[i].end());
//     }
//     // cout << 2 << endl;

//     return res;
// }