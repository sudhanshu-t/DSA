#include<iostream>
#include <unordered_set>

using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input two numbers as range
// It should print required output

void numbers(int l, int r) {
    // Write your code here

    for(int num = l; num <= r; num++){
        unordered_set<int> set;
        bool uni = true;

        // cout << "hello" << endl;

        int safe = num;
        while(num != 0){
            // cout << "Num is " << num << endl;
            int r = num % 10;
            num = num / 10;            
            // cout << "Num is " << num << endl;

            if(set.find(r) == set.end()){
                set.insert(r);
            } else {
                uni = false;
                break;
            }
        }

        // cout << set.size() << endl;

        num = safe;
        if(uni == true){
            cout << num << " ";
        }
    }

    cout << endl;
}

int main(int argc, char** argv){
    int l, r;
    cin>>l>>r;
    numbers(l, r);
}