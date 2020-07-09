#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

void addEdge(vector<vector<string>>& graph, string w1, string w2, unordered_map<string, int>& indices){
    graph[indices[w1]].push_back(w2);
    graph[indices[w2]].push_back(w1);
}

unordered_set<string> used;

bool findMatch(vector<vector<string>>& graph, string w, int idx, unordered_map<string, int>& indices, vector<bool>& visited, unordered_set<string>& w1set, unordered_set<string>& w2set){
    if(idx == 0 && w1set.find(w) != w1set.end()){
        // cout << " found " << w << endl;
        used.insert(w);
        return true;
    }

    if(idx == 1 && w2set.find(w) != w2set.end()){
        used.insert(w);
        return true;
    }

    visited[indices[w]] = true;
    bool found = false;
    int myIdx = (idx == 0) ? 1 : 0;
    for(int i = 0; i < graph[indices[w]].size(); i++){
        string n = graph[indices[w]][i];

        if(myIdx == 0){
            if(w1set.find(n) == w1set.end()){
                if(!visited[indices[n]]){
                    found = findMatch(graph, n, idx, indices, visited, w1set, w2set);
                    if(found == true){
                        return found;
                    }
                }
            }
        } else {
            if(w2set.find(n) == w2set.end()){
                if(!visited[indices[n]]){
                    found = findMatch(graph, n, idx, indices, visited, w1set, w2set);
                    if(found == true){
                        return found;
                    }
                }
            }
        }
    }
    
    visited[indices[w]] = false;
    return found;
}

bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
    if(words2 == words1){
        return true;
    }

    unordered_set<string> w1set;
    for(auto &&i: words1){
        w1set.insert(i);
    }
    unordered_set<string> w2set;
    for(auto &&i: words2){
        w2set.insert(i);
    }

    unordered_set<string> pairUniq;
    for(int i = 0; i < pairs.size(); i++){
        string w1 = pairs[i][0];
        string w2 = pairs[i][1];

        if(pairUniq.find(w1) == pairUniq.end()){
            pairUniq.insert(w1);
        }

        if(pairUniq.find(w2) == pairUniq.end()){
            pairUniq.insert(w2);
        }
    }
    
    vector<vector<string>> graph (pairUniq.size());
    unordered_map<string, int> indices;
    int index = 0;
    // cout << 1 << endl;

    for(int i = 0; i < pairs.size(); i++){
        string w1 = pairs[i][0];
        if(indices.find(w1) == indices.end()) indices[w1] = index++;
        
        string w2 = pairs[i][1];
        if(indices.find(w2) == indices.end()) indices[w2] = index++;

        // cout << 1 << endl;
        addEdge(graph, w1, w2, indices);
    }

    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < words1.size(); i++){
        vector<bool> visited (graph.size());
        // cout << words1[i];
        if(indices.find(words1[i]) != indices.end()){
            bool found = findMatch(graph, words1[i], 1, indices, visited, w1set, w2set);
            if(found){
                used.insert(words1[i]);
                continue;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    for(int i = 0; i < words2.size(); i++){
        vector<bool> visited (graph.size());
        // cout << words2[i];
        if(indices.find(words2[i]) != indices.end()){
            bool found = findMatch(graph, words2[i], 0, indices, visited, w1set, w2set);
            if(found){
                used.insert(words2[i]);
                continue;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    return true;
}


int main(){
    vector<string> words1 = {"one","good","dinner"};
    vector<string> words2 = {"an","extraordinary","meal","meal"};
    vector<vector<string>> pairs = {{"great","good"},{"extraordinary","good"},{"well","good"},{"wonderful","good"},{"excellent","good"},{"fine","good"},{"nice","good"},{"any","one"},{"some","one"},{"unique","one"},{"the","one"},{"an","one"},{"single","one"},{"a","one"},{"truck","car"},{"wagon","car"},{"automobile","car"},{"auto","car"},{"vehicle","car"},{"entertain","have"},{"drink","have"},{"eat","have"},{"take","have"},{"fruits","meal"},{"brunch","meal"},{"breakfast","meal"},{"food","meal"},{"dinner","meal"},{"super","meal"},{"lunch","meal"},{"possess","own"},{"keep","own"},{"have","own"},{"extremely","very"},{"actually","very"},{"really","very"},{"super","very"}};

    cout << areSentencesSimilarTwo(words1, words2, pairs) << endl;
}

// bool getAns(string w, vector<unordered_set<string>>& wset, unordered_map<string, unordered_set<string>>& hm, int idx){
//     unordered_set<string> temp = hm[w];

//     if(wset[0].find(w) != wset[0].end()){
//         idx = 1;
//     } else if(wset[1].find(w) != wset[1].end()){
//         idx = 0;
//     }

//     for(auto itr: temp){
//         if(wset[idx].find(itr) == wset[idx].end()){
//             getAns(itr, wset, hm, idx);
//         } else {
//             return true;
//         }
//     }
    
// }

// bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
//     unordered_map<string, bool> visited;
//     unordered_map<string, unordered_set<string>> hm;

//     for(int i = 0; i < pairs.size(); i++){
//         vector<string> pair = pairs[i];

//         string w1 = pair[0];
//         string w2 = pair[1];

//         if(hm.find(w1) == hm.end()){
//             unordered_set<string> temp;
//             temp.insert(w2);
//             hm[w1] = temp;
//         } else {
//             unordered_set<string> temp = hm[w1];
//             temp.insert(w2);
//             hm[w1] = temp;
//         }

//         if(hm.find(w2) == hm.end()){
//             unordered_set<string> temp;
//             temp.insert(w1);
//             hm[w2] = temp;
//         } else {
//             unordered_set<string> temp = hm[w2];
//             temp.insert(w1);
//             hm[w2] = temp;
//         }
//     }

//     unordered_set<string> w1set;
//     unordered_set<string> w2set;

//     for(int i = 0; i < words1.size(); i++){
//         w1set.insert(words1[i]);
//     }

//     for(int i = 0; i < words2.size(); i++){
//         w2set.insert(words2[i]);
//     }

//     for(int i = 0; i < words1.size(); i++){
//         string w = words1[i];

//         bool matchFound = getAns();
//         if(matchFound){
//             continue;
//         } else {
//             return false;
//         }
//     }

//     for(int i = 0; i < words2.size(); i++){
//         string w = words2[i];

//         bool matchFound = getAns();
//         if(matchFound){
//             continue;
//         } else {
//             return false;
//         }
//     }

//     return true;
// }
