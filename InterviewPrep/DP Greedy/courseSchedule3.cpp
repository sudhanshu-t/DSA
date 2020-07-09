#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

class Solution{
public:
class Pair{
public:
    int duration;
    int end;
    
    Pair(int d, int e){
        duration = d;
        end = e;
    }
    
    bool operator<(const Pair& o) const{
        if(this->duration != o.duration){
            return this->duration < o.duration;
        }
        else {
            return this->end < o.end;    
        }
    }
};

bool sortByEnd(const Pair& a, const Pair& b){
    return a.end < b.end;
}

static int scheduleCourse(vector<vector<int>>& courses) {
    priority_queue<Pair> pq;
    
    vector<Pair> pairs;
    for(int i = 0; i < courses.size(); i++){
        pairs.push_back(Pair (courses[i][0], courses[i][1]));
    }
    
    sort(pairs.begin(), pairs.end(), sortByEnd);

    int tElapsed = 0;
    for(int i = 0; i < pairs.size(); i++){
        if(tElapsed + pairs[i].duration <= pairs[i].end){
            pq.push(pairs[i]);
            tElapsed += pairs[i].duration;
        } else {
            if(pq.size() != 0){
                Pair front = pq.top();
                
                if(front.duration > pairs[i].duration){
                    pq.pop();
                    pq.push(pairs[i]);

                    tElapsed -= front.duration;
                    tElapsed += pairs[i].duration;
                }
            }
        }
    }
    
    return pq.size();
}

};

int main(int argc, char** argv){
    vector<vector<int>> courses = {
        {2500, 3200},
        {100,200},
        {200, 1300},
        {1000, 1250}        
    };

    cout << Solution::scheduleCourse(courses) << endl;
}