#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool comparator(const Interval& A, const Interval& B){
    return A.start < B.start;
}

vector<Interval> merge(vector<Interval> &A) {
    stack<Interval> st;
    sort(A.begin(), A.end(), comparator);
    vector<Interval> res;

    st.push(A[0]);

    for(int i = 1; i < A.size(); i++){
        Interval& top = st.top();

        if(A[i].start <= top.end){
            top.end = (top.end > A[i].end) ? top.end : A[i].end;
        } else {
            st.push(Interval (A[i].start, A[i].end));
        }
    }

    stack<Interval> helper;
    while(st.size() > 0){
        helper.push(st.top());
        st.pop();
    }

    while(helper.size() > 0){
        res.push_back(helper.top());
        helper.pop();
    }
    // sort(A.begin(), A.end(), comparator);    

    return res;
}

int main(){
    vector<Interval> A;
    
    A.push_back(Interval (1,3));
    A.push_back(Interval (8,10));
    A.push_back(Interval (3,6));
    A.push_back(Interval (12,15));
    
    vector<Interval> res = merge(A);
    for(int i = 0; i < res.size(); i++){
        cout << res[i].start << " " << res[i].end << endl;
    }
}
