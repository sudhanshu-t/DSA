#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>

using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input the String s representing the number. It should return
// the most occurring digit in s.
class Pair{
    public:
    int p1;
    int p2;

    Pair(int one, int two){
        p1 = one;
        p2 = two;
    }

    bool operator<(const Pair& o) const {
        if(this->p2 != o.p2){
            return this->p2 < o.p2;
        } else {
            return this->p1 < o.p1;
        }
    }
};

int solve(string& s) {
    // write your code here.
    unordered_map<int, int> map;
    priority_queue<Pair> pq;

    for(int i = 0; i < s.size(); i++){
        map[s[i] - '0']++;
    }

    for(auto itr : map){
        pq.push(Pair (itr.first - '0', itr.second));
    }

    return pq.top().p1 - '0';
}
//Don't make any changes here

int main(int argc,char** argv){
    string s;
    cin>>s;
    cout<<solve(s)<<endl;
}