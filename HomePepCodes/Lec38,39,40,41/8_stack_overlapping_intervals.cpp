#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Interval{
public:
    int start;
    int end;

    Interval(int s, int e){
        this->start = s;
        this->end = e;
    }

    bool operator<(const Interval& o) const{
        return this->start < o.start;
    }
};

void overlapping_interval(vector<int>& starts, vector<int>& ends){
    vector<Interval> ints;

    for(int i = 0; i < starts.size(); i++){
        Interval intv(starts[i], ends[i]);
        ints.push_back(intv);
    }

    sort(ints.begin(), ints.end());

    stack<Interval> st;

    st.push(ints[0]);

    for(int i = 1; i < ints.size(); i++){
        if(ints[i].start < st.top().end){
            st.top().end = max(st.top().end, ints[i].end);
        } else {
            st.push(ints[i]);
        }
    }

    while(st.size() != 0){
        cout << st.top().start << " - " << st.top().end << endl;
        st.pop();
    }

    return;
}

int main(int argc, char** argv){
    vector<int> starts = {2, 6, 12, 3, 22, 17, 19};
    vector<int> ends = {4, 9, 15, 7, 26, 20, 23};

    overlapping_interval(starts, ends);
}