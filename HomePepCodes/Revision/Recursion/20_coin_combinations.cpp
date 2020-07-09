#include <iostream>
#include <string>
#include <vector>

using namespace std;

void sum_level(vector<int> coins, int cc, int sum, string asf){
    if(sum < 0){
        return;
    }

    if(sum == 0){
        cout << asf << endl;
        return;
    }

    for(int i = cc; i < coins.size(); i++){
        sum_level(coins, i, sum - coins[i], asf + to_string(coins[i]));
    }
}

void coin_level(vector<int>& coins, int cc, int sum, string asf){
    if(cc == coins.size()){
        cout << "No coins left" << endl;
        return;
    }
    
    if(sum < 0){
        cout << "sum < 0" << endl;
        return;
    }
    // if(cc == coins.size()){
    if(sum = 0){
        cout << "Hi" << endl;
        cout << asf << endl;
        return;
    }
    
    coin_level(coins, cc + 1, sum, "");
    coin_level(coins, cc, sum - coins[cc], asf + to_string(coins[cc]));
}

int main(int argc, char** argv){
    vector<int> coins = {2,5,3};

    sum_level(coins, 0, 7, "");
    // coin_level(coins, 0, 7, "");
}