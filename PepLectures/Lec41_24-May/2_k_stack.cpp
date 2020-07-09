#include <iostream>
using namespace std;

class kstacks{
private:
    int* da;
    int* pa;
    int* sha;
    int fh;
    int cap;

public:
    kstacks(int cap, int k){
        this->da = new int[cap];
        this->pa = new int[cap];
        this->sha = new int[k];
        this->fh = 0;
        this->cap = cap;

        for(int i = 0; i < cap; i++){
            this->da[i] = 0;
            this->pa[i] = i + 1;
        }

        this->pa[cap - 1] = -1;

        for(int i = 0; i < k; i++){
            this->sha[i] = -1;
        }
    }

    bool is_full(){
        if(this->fh == -1){
            return true;
        } else {
            return false;
        }
    }

    bool is_empty(int s){
        if(this->sha[s] == -1){
            return true;
        } else {
            return false;
        }
    }

    void push(int val, int s){
        if(is_full()){
            cout << "Stack Overflow" << endl;
        } else {
            int nh = fh; // Inflexion point

            fh = pa[fh]; // remove first in free

            pa[nh] = sha[s]; // add first in stack : line 1
            sha[s] = nh; // add first in stack : line 2

            da[nh] = val;
        }
    }

    int top(int s){
        if(is_empty(s)){
            // cout << "Stack Underflow" << endl;
            return -1;
        } else {
            return da[sha[s]];
        }
    }

    void pop(int s){
        if(is_empty(s)){
            cout << "Stack Underflow" << endl;
        } else {
            int nfh = sha[s]; // Inflexion point

            sha[s] = pa[sha[s]]; // Remove first in stack 

            pa[nfh] = fh; // Add first in free : line 1
            fh = nfh; // Add first in free : line 2

            da[nfh] = 0;
        }
    }
};

int main(int argc, char** argv){
    kstacks ks(10, 2);

    ks.push(10, 0);
    ks.push(20, 0);
    ks.push(30, 1);
    ks.push(40, 1);
    ks.push(50, 0);
    ks.push(60, 2);
    ks.push(70, 1);
    ks.push(80, 2);
    ks.push(90, 2);
    ks.push(100, 1);
    ks.push(110, 1);

    for(int i = 0; i <= 2; i++){
        cout << i << " : ";

        while(!ks.is_empty(i)){
            int val = ks.top(i);
            ks.pop(i);

            cout << val << " ";
        }
        cout << endl;
    }

    ks.pop(1);

    return 0;
}