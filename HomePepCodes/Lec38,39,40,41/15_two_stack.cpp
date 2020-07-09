#include <iostream>
using namespace std;

class two_stack{
private:
    int* data;
    int t1;
    int t2;
    int cap;

public:
    two_stack(int cap){
        data = new int[cap];
        this->cap = cap;

        t1 = -1;
        t2 = cap;
    }

    void push_1(int val){
        if(t1 == cap - 1 || t1 + 1 == t2){
            cout << "Stack 1 Overflow" << endl;
            return;
        }

        t1++;
        data[t1] = val;
    }

    void push_2(int val){
        if(t2 == 0 || t2 - 1 == t1){
            cout << "Stack 2 Overflow" << endl;
            return;
        }

        t2--;
        data[t2] = val;
    }

    int top_1(){
        if(t1 == -1){
            return -1;
        }
        
        return data[t1];
    }

    int top_2(){
        if(t2 == cap){
            return -1;
        }

        return data[t2];
    }

    void pop_1(){
        if(t1 == -1){
            cout << "Stack 1 Underflow" << endl;
            return;
        }

        data[t1] = 0;
        t1--;
    }

    void pop_2(){
        if(t2 == cap){
            cout << "Stack 2 Underflow" << endl;
            return;
        }

        data[t2] = 0;
        t2++;
    }

    int size_1(){
        return t1 + 1;
    }

    int size_2(){
        return cap - t2;
    }

    bool is_full(){
        if(t1 + 1 == t2){
            return true;
        } else {
            return false;
        }
    }
};

int main(int argc, char** argv){
    two_stack ts(5);

    ts.push_2(10);
    ts.push_1(20);
    ts.push_2(30);
    ts.push_1(40);
    ts.push_2(50);
    ts.push_1(60);

    while(ts.size_1() > 0){
        cout << ts.top_1() << " ";
        ts.pop_1();
    }
    
    cout << endl;

    while(ts.size_2() > 0){
        cout << ts.top_2() << " ";
        ts.pop_2();
    }

    cout << endl;

    ts.pop_1();
    ts.pop_2();
}