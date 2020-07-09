#include <bits/stdc++.h>
using namespace std;

class helper{
public:
    int i;
    int j;
    int d;
    helper(int x, int y, int z){
        i = x;
        j = y;
        d = z;
    }
};

void makeTwo(vector<vector<int>>& A, int i, int j){
    queue<helper> q;
    q.push(helper(i, j, 0));
    while(!q.empty()){
        helper f = q.front();
        q.pop();
        
        if(A[f.i][f.j] == 1){
            A[f.i][f.j] = 2;
        } else {
            continue;
        }
        
        if(f.i-1 >= 0 && A[f.i-1][f.j] == 1){
            q.push(helper(f.i-1, f.j, 0));
        }
        
        if(f.j-1 >= 0 && A[f.i][f.j-1] == 1){
            q.push(helper(f.i, f.j-1, 0));
        }
        
        if(f.i+1 < A.size() && A[f.i+1][f.j] == 1){
            q.push(helper(f.i+1, f.j, 0));
        }
        
        if(f.j+1 < A[0].size() && A[f.i][f.j+1] == 1){
            q.push(helper(f.i, f.j+1, 0));
        }
    }
}

int findDist(vector<vector<int>>& A, int i, int j){
    queue<helper> q;
    q.push(helper(i,j,0));
    
    int myMin = 110;
    
    while(!q.empty()){
        helper f = q.front();
        q.pop();
        
        if(A[f.i][f.j] == 1){
            if(myMin > f.d-1){
                myMin = f.d-1;
            }
            continue;
        }
        
        if(A[f.i][f.j] != 3){
            A[f.i][f.j] = 3;
        } else {
            continue;
        }

        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[0].size(); j++){
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        if(f.i-1 >= 0){
            if(A[f.i-1][f.j] == 0 || A[f.i-1][f.j] == 1){
                if(A[f.i-1][f.j] == 1)
                    cout << "Inserting 1 with dist " << f.d+1 << endl;

                q.push(helper(f.i-1, f.j, f.d+1));
            }
            if(A[f.i-1][f.j] == 2){
                q.push(helper(f.i-1, f.j, 0));
            }
        }
        
        if(f.j-1 >= 0){
            if(A[f.i][f.j-1] == 0 || A[f.i][f.j-1] == 1){
                if(A[f.i][f.j-1] == 1)
                    cout << "Inserting 1 with dist " << f.d+1 << endl;

                q.push(helper(f.i, f.j-1, f.d+1));
            }
            if(A[f.i][f.j-1] == 2){
                q.push(helper(f.i, f.j-1, 0));
            }
        }
        
        if(f.i+1 < A.size()){
            if(A[f.i+1][f.j] == 0 || A[f.i+1][f.j] == 1){
                q.push(helper(f.i+1, f.j, f.d+1));

                if(A[f.i+1][f.j] == 1)
                    cout << "Inserting 1 with dist " << f.d+1 << endl;
            }
            if(A[f.i+1][f.j] == 2){
                q.push(helper(f.i+1, f.j, 0));
            }
        }
        
        if(f.j+1 < A[0].size()){
            if(A[f.i][f.j+1] == 0 || A[f.i][f.j+1] == 1){
                if(A[f.i][f.j+1] == 1)
                    cout << "Inserting 1 with dist " << f.d+1 << endl;

                q.push(helper(f.i, f.j+1, f.d+1));
            }
            if(A[f.i][f.j+1] == 2){
                q.push(helper(f.i, f.j+1, 0));
            }
        }
    }
    
    return myMin;
}

int shortestBridge(vector<vector<int>>& A) {
    queue<helper> q;
    
    bool done = false;
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[0].size(); j++){
            if(!done && A[i][j] == 1){
                makeTwo(A, i, j);
                done = true;
                break;
            }
        }
    }

    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[0].size(); j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    int dist;
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[0].size(); j++){
            if(A[i][j] == 2){
                dist = findDist(A, i, j);
            }
        }
    }

    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[0].size(); j++){
            cout << A[i][j] << " ";
        }

        cout << endl;
    }
    
    return dist;
}

int main(){
    // vector<vector<int>> A = {
    //     {1,1,1,0,0},
    //     {1,1,1,0,0},
    //     {1,1,0,0,0},
    //     {0,0,0,1,1},
    //     {0,0,1,1,1}
    // };

    // vector<vector<int>> A = {
    //     {0,0,0,0,0,0,0},
    //     {1,0,0,0,0,0,0},
    //     {1,0,0,0,0,0,0},
    //     {1,1,0,0,0,0,0},
    //     {0,1,0,1,1,1,0},
    //     {0,0,0,0,0,0,0},
    //     {0,0,0,0,0,0,0}
    // };

    vector<vector<int>> A = {{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,1,0,0},{0,0,0,0,1,0,0},{1,1,0,1,1,0,0},{1,1,0,1,1,0,0}};
    cout << shortestBridge(A) << endl;
}