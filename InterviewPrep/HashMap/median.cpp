#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;

class Median{
private:
   
    void rebalance(){
        if(lpq.size() - rpq.size() == 2){
            int top = lpq.top();
            lpq.pop();
            rpq.push(top);
        } else if(rpq.size() - lpq.size() == 2){
            int top = rpq.top();
            rpq.pop();
            lpq.push(top);
        }
    }

     priority_queue<int> lpq;
    priority_queue<int, vector<int>, greater<int>> rpq;

    
public:
    void push(int val){
        if(lpq.size() != 0 && val < lpq.top()){
            lpq.push(val);
        } else {
            rpq.push(val);
        }

        rebalance();

        double rv;
        
        if((lpq.size() + rpq.size()) % 2 == 0){
            rv = (double)(lpq.top() + rpq.top()) / 2;
        } else {
            rv = (double) rpq.top();
        }
        
        cout << fixed << setprecision(1) << rv << endl;
    }
};

void median(vector<int>& stocks){
    Median pq;

    for(int i = 0; i < stocks.size(); i++){
        pq.push(stocks[i]);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    vector<int> stocks(n);
    
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        stocks[i] = x;        
    }

    median(stocks);
        
    return 0;
}
