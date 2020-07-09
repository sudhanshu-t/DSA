#include <iostream>
#include <list>
#include <vector>

using namespace std;

class P{
    public:
    int data;
    string s;

    P(int d, string s){
        data = d;
        this->s = s;
    }
};

void getBinary(int n){
//write your code here
    list<P> q;
    q.push_back(P (1, "1"));

    while(q.size()){
        P front = q.front(); q.pop_front();

        cout << front.s << " ";

        if(2*front.data <= n){
            q.push_back(P (2 * front.data, front.s + "0"));
            q.push_back(P (2 * front.data + 1, front.s + "1"));
        }
    }
}

int main(){
    int n; cin >> n;
    getBinary(n);       
}