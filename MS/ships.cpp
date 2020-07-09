#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


int solve(int v, int l, int m, int level, vector<vector<int>>& qb){
    if(level == l){
        return 0;
    }
    
    if(qb[v][level] != -1){
        return qb[v][level];
    }

    int op = ((v*v) + 1) % m;
    int sum = 0;
    for(int i = 0; i < op; i++){
        sum += solve(i, l, m, level + 1, qb);
        qb[i][level + 1] = solve(i, l, m, level + 1, qb);
    }

    qb[v][level] = sum + 1;
    return qb[v][level] % m;
}

float round(float var) 
{ 
    // we use array of chars to store number 
    // as a string. 
    char str[40];  
  
    // Print in string the value of var  
    // with two decimal point 
    sprintf(str, "%.5f", var); 
  
    // scan string value in var  
    sscanf(str, "%f", &var);  
  
    return var;  
}

int main(int argc, char** argv){
    // int l, m;
    // cin >> l >> m;

    // vector<vector<int>> qb(m, vector<int> (l, -1));

    // cout << solve(2, l, m, 0, qb) << endl;

    float c = 1.234;
    cout << fixed << setprecision(10) << c << endl;
    // fixed;
    c = round(c);
    cout << c << endl;
}