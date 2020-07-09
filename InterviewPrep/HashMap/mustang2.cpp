#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

class Pair{
    public:
    int dis;
    int fuel;
    
    Pair(int d, int f){
        dis = d;
        fuel = f;
    }
    
    bool operator<(const Pair& o) const{
        return this->dis < o.dis;   
    }
};

int mustang(vector<int>& d, vector<int>& f, int currf, int target){
    unordered_map<int, vector<int>> map;
    
    int currd = 0;
    int count = 0;
    
    for(int i = 0; i < d.size(); i++){
        if(map.find(d[i]) == map.end()){
            vector<int> temp;
            temp.push_back(f[i]);
            map[d[i]] = temp;
        } else {
            map[d[i]].push_back(f[i]);
        }
    }
    
    priority_queue<Pair> pq;
    
    while(true){
        for(auto itr : map){
            if(itr.first <= currf){
                for(int i = 0; i < itr.second.size(); i++){
                    pq.push(Pair (itr.first, itr.second[i]));
                }
                map.erase(itr.first);
            }
        }
        
        Pair max = pq.top();
        
        currd += max.dis;
        currf = currf - max.dis + max.fuel;
        
        count++;
        
        if(currd + currf >= target){
            break;
        }
    }
    
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int dest, startf, n;

    cin >> dest;
    cin >> startf;
    cin >> n;

    vector<int> d (n);
    vector<int> f (n);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        d[i] = x;
    }

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        f[i] = x;
    }

    cout << mustang(d, f, startf, dest) << endl;

    return 0;
}
