#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int slave(vector<vector<char>>& cake, int k, int s, int i, int j, unordered_map<int, int>& rmap, unordered_map<int, int>& cmap){
    if(k > s){
        for(int ii = i; ii < cake.size(); ii++){
            for(int jj = j; jj < cake[0].size(); jj++){
                cout << cake[ii][jj] << " ";
            }
            cout << endl;
        }
        cout << "No way" << endl << endl;
        return 0;
    }

    if(k == 1){
        for(int ii = i; ii < cake.size(); ii++){
            for(int jj = j; jj < cake[0].size(); jj++){
                cout << cake[ii][jj] << " ";
            }
            cout << endl;
        }

        cout << "Count is: " << 1 << endl;
        cout << endl;

        return 1;
    }

    // horizontal cuts
    int count = 0;
    for(int ii = i; ii < cake.size() - 1; ii++){
        int rc = rmap[ii];
        count += slave(cake, k-1, s - rc, ii+1, j, rmap, cmap);
    }

    // vertical cuts
    for(int jj = 0; jj < cake[0].size() - 1; jj++){
        int cc = cmap[jj];
        count += slave(cake, k-1, s - cc, i, jj+1, rmap, cmap);
    }

    for(int ii = i; ii < cake.size(); ii++){
        for(int jj = j; jj < cake[0].size(); jj++){
            cout << cake[ii][jj] << " ";
        }
        cout << endl;
    }
    cout << "Count is: " << count << endl;
    cout << endl;

    return count;
}

int noOfWays(vector<vector<char>>& cake, int k){
    int sCount = 0;
    unordered_map<int, int> rmap;
    unordered_map<int, int> cmap;
    for(int i = 0; i < cake.size(); i++){
        int rc = 0;
        for(int j = 0; j < cake[0].size(); j++){
            if(cake[i][j] == 'v'){
                sCount++;
                rc++;
            }
        }
        rmap[i] = rc + ((i > 0) ? rmap[i-1] : 0);
    }

    for(int j = 0; j < cake[0].size(); j++){
        int cc = 0;
        for(int i = 0; i < cake.size(); i++){
            if(cake[i][j] == 'v'){
                cc++;
            }
        }

        cmap[j] = cc + ((j > 0) ? cmap[j-1] : 0);
    }

    return slave(cake, k, sCount, 0, 0, rmap, cmap);
}

int main(){
    vector<vector<char>> cake = {
        {'v','v','v'},
        {'v','.','.'},
        {'v','.','.'}
    };

    int k = 3;

    cout << noOfWays(cake, k) << endl;
}