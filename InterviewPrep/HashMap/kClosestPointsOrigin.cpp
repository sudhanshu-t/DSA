#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include <stack>

using namespace std;

// -----------------------------------------------------
// This is a functional problem. Do not change main
// This function takes as input a 2d array and k value
// It should return required output as 2d array
class Pair{
    public:
    int i;
    int j;

    Pair(int i, int j){
        this->i = i;
        this->j = j;
    }

    bool operator>(const Pair& o) const {
        int i1 = this->i;
        int j1 = this->j;
        int i2 = o.i;
        int j2 = o.j;
        if(i1*i1 + j1*j1 != i2*i2 + j2*j2){
            return i1*i1 + j1*j1 > i2*i2 + j2*j2;
        } else {
            return (i1 <= i2) ? false : true;
        }
    }
};

vector<vector<int> > kClosest(vector<vector<int> >& points, int K) {
    //Write your code here
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    vector<vector<int>> ans;

    for(int i = 0; i < points.size(); i++){
        pq.push(Pair (points[i][0], points[i][1]));
    }

    stack<Pair> st;
    for(int i = 0; i < K; i++){
        Pair top = pq.top(); pq.pop();
        st.push(top);
    }

    while(st.size() != 0){
        vector<int> temp (2);
        temp[0] = st.top().i;
        temp[1] = st.top().j;
        ans.push_back(temp);
        st.pop();
    }

    return ans;
}
int main(int argc,char** argv){
    int row;
    cin>>row;
    vector<vector<int> > points(row,vector<int> (2));
    for(int i=0;i<row;i++){
        for(int j=0;j<2;j++){
            cin>>points[i][j];
        }
    }
    int k;
    cin>>k;
    vector<vector<int> > res=kClosest(points,k);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<2;j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
}