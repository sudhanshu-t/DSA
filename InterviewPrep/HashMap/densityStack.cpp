#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class DensityStack{
    private:
    int top;
    int size;
    int maxF;
    unordered_map<int, int> map;
    
    public:
    DensityStack(){
        size = 0;
        top = 0;
        maxF = 0;
    }
    
    void push(int x){
        size++;
        map[x]++;
        
        if(map[x] >= maxF){
            maxF = map[x];
            top = x;
        }
        
        cout << "null" << endl;
    }
    
    int pop(){
        if(size == 0){
            return -1;
        }
        
        return top;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    DensityStack obj;
    
    for(int i = 0; i < n+1; i++){
        string s;
        getline(cin, s);

        if(s[1] == 'o'){
            cout << obj.pop() << endl;   
        }
        
        else if(s[1] == 'u'){
            string num = s.substr(5);
            int x = stoi(num);
            
            obj.push(x);
        }
        
        // else {
        //     cout << "null" << endl;
        // }
    }
    
    
    return 0;
}
