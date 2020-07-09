#include <bits/stdc++.h>
using namespace std;

class item{
public:
    int x;
    int y;
    int t;
    
    item(int x, int y, int t) {
        this->x = x;
        this->y = y;
        this->t = t;
    }
};

static bool comptor(vector<int>& a, vector<int>& b) {
    if(a[0] != b[0]) 
        return a[0] < b[0];
    return a[1] > b[1];        
}

vector<vector<int>> getSkyline(vector<vector<int>>& b) {
    priority_queue<int> pq;
    vector<vector<int>> items;
    
    for (int i = 0; i < b.size(); i++) {
        items.push_back({b[i][0], b[i][2]});
        items.push_back({b[i][1], -b[i][2]});
    }
    
    sort(items.begin(), items.end(), comptor);
    
    vector<vector<int>> res;
    pq.push(0);
    for (auto i: items) {
        int prevMax = pq.top();
        if (i[1] > 0) {
            pq.push(i[1]);
        } else {
            priority_queue<int> copy;
            while (pq.top() != abs(i[1])) {
                copy.push(pq.top());
                pq.pop();
            }
            
            pq.pop();
            
            if (copy.size() >= pq.size()) {
                while (!pq.empty()) {
                    copy.push(pq.top());
                    pq.pop();
                }
                
                pq = copy;
            } else {
                while (!copy.empty()) {
                    pq.push(copy.top());
                    copy.pop();
                }
            }
        }
        
        int newMax = pq.top();
        if (prevMax != newMax) {
            res.push_back({i[0], newMax});
        }
    }
    
    return res;
}

int main() {
    vector<vector<int>> rect = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> res = getSkyline(rect);
    cout << res.size() << endl;
    for (auto i: res) {
        cout << i[0] << ", " << i[1] << endl;
    }
}