#include <iostream>
#include <string>
#include <vector>

using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};

void ss(string q, string a){
    if(q.size() == 0){
        cout << a << endl;
        return;
    }

    char ch = q[0];
    string roq = q.substr(1);

    ss(roq, a + "-");
    ss(roq, a + ch);
}

int counter = 0;

void kpc(string q, string a){
    if(q.length() == 0){
        cout << a << endl;
        counter++;
        return ;
    }

    char s = q[0];
    string roq = q.substr(1);
    string str = codes[s - '0'];

    for(int i = 0; i < str.size(); i++){
        char asf = str[i];
        string s(1, asf);
        // cout << asf << endl;
        kpc(roq, a + s);
    }
}

void stair(int n, string asf){
    if(n == 0){
        cout << asf << endl;
        return;
    }

    if(n < 0){
        return;
    }

    // Reactive approach
    stair(n-1, asf + "1");
    stair(n-2, asf + "2");
    stair(n-3, asf + "3");
}

void printMaze(int cr, int cc, int dr, int dc, string asf){
    if(cr == dr && cc == dc){
        cout << asf << endl;
        return;
    }

    if(cr > dr || cc > dc){
        return;
    }

    printMaze(cr+1, cc, dr, dc, asf + "v");
    printMaze(cr, cc+1, dr, dc, asf + "h");
}

void printMaze2(int cr, int cc, int dr, int dc, string asf){
    if(cc == dc && cr == dr){
        cout << asf << endl;
        return;
    }

    if(cc > dc || cr > dr){
        return;
    }

    for(int i = 1; i <= dc; i++){
        printMaze2(cr, cc + i, dr, dc, asf + "h" + to_string(i));
    }

    for(int i = 1; i <= dr; i++){
        printMaze2(cr + i, cc, dr, dc, asf + "v" + to_string(i));
    }

    for(int i = 1; i <= dc && i <= dr; i++){
        printMaze2(cr + 1, cc + 1, dr, dc, asf + "d" + to_string(i));
    }
}

vector <vector <int>> tarsum(int arr[], int vidx, int n, int sum){
    if(vidx == n-1 && sum == arr[vidx]){
        vector <vector <int>> bres;
        return bres;
    }

    if(vidx + 1 < n){
        vector <vector <int>> rres = tarsum(arr, vidx+1, n, sum - arr[vidx]);



        for(int i = 0; i < rres.size(); i++){
            rres[i].push_back(arr[vidx]);
        }   


        return rres;
    }
}

int main(int argc, char** argv){
    // ss("abc", "");
    kpc("682", "");
    cout << counter << endl;
    // stair(8, "");
    // printMaze2(0, 0, 2, 2, "");
    // printMaze2(0, 0, 2, 2, "");

    int arr[] = {1,2,3,4,5,6,7};

    int size = sizeof(arr);
    
    vector <vector <int>> ans = tarsum(arr, 0, size, 10);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }

    // return 0;
}