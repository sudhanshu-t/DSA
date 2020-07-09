#include <climits>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input 2D array
// It should return the required output
//   int sum = 0;

class helper{
public:
    int p1i;
    int p1j;
    int p2i;
    int state;
    int sum = 0;

    helper(int p1i, int p1j, int p2i, int state){
        this->p1i = p1i;
        this->p1j = p1j;
        this->p2i = p2i;
        this->state = state;
    }
};

int cherryPickupIterativeDFS(vector<vector<int>>& grid){
    stack<helper*> st;

    vector<vector<vector<int>>> qb (grid.size(), vector<vector<int>> (grid.size(), vector<int> (grid.size(), INT_MIN)));

    st.push(new helper(0,0,0,0));

    while(st.size()){
        helper* top = st.top();

        int p2j = (top->p1i + top->p1j) - top->p2i;

        int sum = 0;

        if(top->p1i == grid.size() || top->p1j == grid.size() ||
           top->p2i == grid.size() || p2j == grid.size() ||
           grid[top->p1i][top->p1j] == -1 || grid[top->p2i][p2j] == -1){
               st.pop();
               continue;
           }

        if(qb[top->p1i][top->p1j][top->p2i] != INT_MIN){
            top->sum += qb[top->p1i][top->p1j][top->p2i];
            st.pop();
            continue;
        }

        if(top->state == 0){
            st.push(new helper(top->p1i + 1, top->p1j, top->p2i, 0));
            top->state++;
        } else if(top->state == 1){
            st.push(new helper(top->p1i + 1, top->p1j, top->p2i + 1, 0));
            top->state++;
        } else if(top->state == 2){
            st.push(new helper(top->p1i, top->p1j + 1, top->p2i, 0));
            top->state++;
        } else if(top->state == 3){
            st.push(new helper(top->p1i, top->p1j + 1, top->p2i + 1, 0));
            top->state++;
        } else {
            // top->sum += max()
            // pop
            // pop again and add sum to this popped value
        }
    }
}

int cherryPickupPrivate(vector<vector<int>>& grid, vector<vector<vector<int>>>& qb, int p1i, int p1j, int p2i){
    int p2j = p1i + p1j - p2i;
    
    if(p1i >= grid.size() || p2i >= grid.size() ||
        p1j >= grid[0].size() || p2j >= grid[0].size()){
            return INT_MIN;
        }

    if(grid[p1i][p1j] == -1 || grid[p2i][p2j] == -1){
        return INT_MIN;
    }
    
    if(qb[p1i][p1j][p2i] != INT_MIN){
        return qb[p1i][p1j][p2i];
    }
    
    if(p1i == grid.size()-1 && p1j == grid[0].size() - 1){
        qb[p1i][p1j][p2i] = grid[p1i][p1j];
        return qb[p1i][p1j][p2i];
    }
    
    int sum = 0;
    if(p1i == p2i && p1j == p2j){
        if(grid[p1i][p1j] == 1)
            sum += 1;
    }
    
    else if(p1i != p2i || p1j != p2j){
        sum += grid[p1i][p1j] + grid[p2i][p2j];
    }

    int a = cherryPickupPrivate(grid, qb, p1i + 1, p1j, p2i + 1);
    int b = cherryPickupPrivate(grid, qb, p1i + 1, p1j, p2i);
    int c = cherryPickupPrivate(grid, qb, p1i, p1j + 1, p2i + 1);
    int d = cherryPickupPrivate(grid, qb, p1i, p1j + 1, p2i);
    
    sum += max(d, max(c, max(a,b)));
    // cout << sum << endl;
    qb[p1i][p1j][p2i] = sum;
    return sum;
}

int cherryPickup(vector<vector<int>>& grid) {
    vector<vector<vector<int>>> qb (grid.size(), vector<vector<int>>(grid.size(), vector<int> (grid.size(), INT_MIN)));
    
    int res = cherryPickupPrivate(grid, qb, 0, 0, 0);
    return (res < 0) ? 0 : res;
}


int main(int argc,char**argv){

    int r,c;
    cin>>r>>c;          
    vector< vector<int> >grid(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>grid[i][j];
        }
    }   
    cout<<cherryPickup(grid);
}