#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int getAns(vector<vector<char>>& cake, int i, int j, int s, int k, vector<int> row, vector<int> col){
    if(k > s){
        return 0;
    }

    if(k == 1){
        return 1;
    }

    int count = 0;

    for(int ii = i; ii < cake.size(); ii++){
        vector<int> rowCpy = row;
        vector<int> colCpy = col;

        int rc = 0;
        for(int r = i; r <= ii; r++){
            rc += row[r];
        }

        if(rc == 0){
            continue;
        }

        for(int c = j; c < cake[0].size()-1; c++){
            for(int r = i; r <= ii; r++){
                if(cake[r][c] == 'v'){
                    col[c]--;
                }
            }
        }
        
        count += getAns(cake, ii+1, j, s - rc, k-1, row, col);

        row = rowCpy;
        col = colCpy;
    }

    for(int jj = j; jj < cake[0].size()-1; jj++){
        vector<int> rowCpy = row;
        vector<int> colCpy = col;

        int cc = 0;
        for(int c = j; c <= jj; c++){
            cc += col[c];
        }

        if(cc == 0){
            continue;
        }

        for(int r = i; r < cake.size(); r++){
            for(int c = j; c <= jj; c++){
                if(cake[r][c] == 'v'){
                    row[r]--;
                }
            }
        }

        count += getAns(cake, i, jj+1, s - cc, k-1, row, col);

        row = rowCpy;
        col = colCpy;
    }

    return count;
}

int noOfWays(vector<vector<char>>& cake, int k){
    int s = 0;
    for(int i = 0; i < cake.size(); i++){
        for(int j = 0; j < cake[0].size(); j++){
            if(cake[i][j] == 'v') s++;
        }
    }

    vector<int> row (cake.size());
    vector<int> col (cake[0].size());

    for(int i = 0; i < cake.size(); i++){
        int rc = 0;
        for(int j = 0; j < cake[0].size(); j++){
            if(cake[i][j] == 'v'){
                rc++;
            }
        }
        row[i] = rc;
    }

    for(int j = 0; j < cake[0].size(); j++){
        int cc = 0;
        for(int i = 0; i < cake.size(); i++){
            if(cake[i][j] == 'v'){
                cc++;
            }
        }
        col[j] = cc;
    }

    return getAns(cake, 0, 0, s, k, row, col);
}

int getans(vector<vector<int>> &matrix , int xl , int xh , int yl , int yh , int k){
    if((xl>xh)||(yl>yh))
        return 0;
    if((k==1)&&(xh>=xl)&&(yh>=yl))
        return 1;
    int count=0;
    vector<int> xcount(xh-xl+1,0);
    vector<int> ycount(yh-yl+1,0);
    for(int i=xl;i<=xh;i++){
        for(int j=yl;j<=yh;j++){
            if (matrix[i][j]){
                xcount[i-xl]+=1;
                ycount[j-yl]+=1;
            }
        }
    }
    for(int i =1; i<xcount.size();i++){
        xcount[i]+=xcount[i-1];
    }
    for(int i =1; i<ycount.size();i++){
        ycount[i]+=ycount[i-1];
    }
    for(int i = xl; i<xh ; i++){
        if ((xcount[i-xl]>0) && ((xcount[xcount.size()-1] - xcount[i-xl])>0))
            count+=getans(matrix,i+1,xh,yl,yh,k-1);
    }
    for(int i = yl; i<yh ; i++){
        if ((ycount[i-yl]>0) && ((ycount[ycount.size()-1] - ycount[i-yl])>0))
            count+=getans(matrix,xl,xh,i+1,yh,k-1);
    }
    return count;
}

int main(){
    // vector<vector<char>> cake = {
    //     {'v','v','v'},
    //     {'v','.','.'},
    //     {'v','.','.'}
    // };
    // vector<vector<char>> cake = {
    //     {'.','.','.','v'},
    //     {'.','.','.','v'},
    //     {'.','.','.','v'},
    //     {'.','.','.','v'}
    // };

    // vector<vector<char>> cake = {
    //     {'v','v'},
    //     {'v','v'}
    // };
    
    // vector<vector<char>> cake = {
    //     {'v', '.', 'v'},
    //     {'.', '.', '.'},
    //     {'v', '.', 'v'},
    // };

    // vector<vector<char>> cake = {
    //     {'v','v','v','v','v','v','v','v','v','v'},
    //     {'v','v','v','v','v','v','v','v','v','v'},
    //     {'v','v','v','v','v','v','v','v','v','v'},
    //     {'v','v','v','v','v','v','v','v','v','v'},
    //     {'v','v','v','v','v','v','v','v','v','v'},
    //     {'v','v','v','v','v','v','v','v','v','v'},
    //     {'v','v','v','v','v','v','v','v','v','v'},
    //     {'v','v','v','v','v','v','v','v','v','v'},
    //     {'v','v','v','v','v','v','v','v','v','v'},
    //     {'v','v','v','v','v','v','v','v','v','v'},
    // };

    // int k = 5;

    // cout << noOfWays(cake, k) << endl;

    int t;
    cin>>t;
    while(t--){
        int h,w,k;
        cin>>h>>w>>k;
        vector< vector<int> > matrix;
        matrix.resize(h , vector<int>(w,0));
        for(int i=0;i<h;i++){
            string s;
            cin>>s;
            for(int j=0;j<w;j++){
                if(s[j]=='v')
                    matrix[i][j]=1;
            }
        }
        cout<<getans(matrix,0,h-1,0,w-1,k)<<endl;
    }
}