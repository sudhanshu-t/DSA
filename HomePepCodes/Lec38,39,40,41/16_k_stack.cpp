#include <iostream>
using namespace std;

class k_stack{
private:
    int* da;
    int* pa;
    int* sha;
    int fh;
    int cap;

public:
    k_stack(int cap, int k){
        this->da = new int[cap];
        this->pa = new int[cap];
        this->sha = new int[k];
        this->fh = 0;
        this->cap = cap;

        for(int i = 0; i < cap; i++){
            this->da[i] = -1;
            this->pa[i] = i + 1;
        }

        this->pa[cap - 1] = -1;

        for(int i = 0; i < k; i++){
            this->sha[i] = -1;
        }
    }

    void push(int val, int k){
        if(is_full()){
            cout << "Stack " << k << " Overflow" << endl;
            return;
        }

        int nh = fh;
        
        // Remove first from free list
        fh = pa[fh];

        // Add first to stack
        pa[nh] = sha[k];
        sha[k] = nh;

        da[nh] = val;
    }

    int top(int k){
        if(is_empty(k)){
            return -1;
        }
        
        return da[sha[k]];
    }

    void pop(int k){
        if(is_empty(k)){
            cout << "Stack " << k << " Underflow" << endl;
            return;
        }

        int nfh = sha[k];

        // Remove first from stack
        sha[k] = pa[nfh];        

        // Add first to free list
        pa[nfh] = fh;
        fh = nfh;

        da[nfh] = -1;
    }

    bool is_empty(int k){
        if(sha[k] == -1){
            return true;
        } else {
            return false;
        }
    }

    bool is_full(){
        if(fh == -1){
            return true;
        } else {
            return false;
        }
    }
};

int main(int argc, char** argv){
    k_stack ks(10, 3);

    ks.push(10,0);
    ks.push(20,1);
    ks.push(30,2);
    ks.push(40,0);
    ks.push(50,2);
    ks.push(60,1);
    ks.push(70,0);
    ks.push(80,0);
    ks.push(90,1);
    ks.push(100,0);
    ks.push(110,0);

    for(int i = 0; i < 3; i++){
        cout << i << " : ";
        while(!ks.is_empty(i)){
            cout << ks.top(i) << " ";
            ks.pop(i);
        }

        cout << endl;
    }

    ks.pop(2);
}