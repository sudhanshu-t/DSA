#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int maxSize(vector<int>& v){
    int mymax = 0;
    vector<bool> visited (v.size(), false);

    unordered_set<int> set;
    // index vs freq
    
    for(int i = 0; i < v.size(); i++){
        int count = 0;

        int x = v[i];

        if(set.find(i) == set.end()){
            set.insert(i);

            int idx = x;
            x = v[x];

            while(set.find(idx) == set.end()){
                
            }
        }
    }

    return mymax;
}

int main(int argc, char** argv){
    int n;
    cin >> n;

    vector<int> v;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        v.push_back(x);
    }

    cout << maxSize(v) << endl;
}

// if(visited[v[i]] == false){
//     visited[v[i]] = true;

//     count = 1;
//     int x = v[v[i]];
//     while(visited[x] != true && x != v[i]){
//             visited[x] = true;
//             x = v[x];
//             count++;
//     }

//     cout << count << endl;

//     mymax = max(count, mymax);
// }