#include <iostream>
#include <string>
#include <vector>

using namespace std;

void sum_level(vector<int> coins, int sum, string asf){
    if(sum < 0){
        return;
    }

    if(sum == 0){
        cout << asf << endl;
        return;
    }

    for(int i = 0; i < coins.size(); i++){
        sum_level(coins, sum - coins[i], asf + to_string(coins[i]));
    }
}

int main(int argc, char** argv){
    vector<int> coins = {2,5,3};

    sum_level(coins, 7, "");
    // coin_level(coins, 0, 7, "");
}