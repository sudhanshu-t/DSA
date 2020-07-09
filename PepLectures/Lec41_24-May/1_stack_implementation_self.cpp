#include <iostream>

using namespace std;

class my_stack{
private:
    int* data;
    int cap;
    int tos;

public:
    my_stack(int cap){
        this->data = new int[cap];
        this->cap = cap;
        this->tos = -1;
    }

    void push(int val){
        if(tos == cap - 1){
            cout << "Stack Overflow" << endl;
            return;
        }
        
        tos++;
        data[tos] = val;
    }

    void pop(){
        if(tos == -1){
            cout << "Stack Underflow" << endl;
            return;
        }

        data[tos] = 0;
        tos--;
    }

    int top(){
        if(tos == -1){
            return -1;
        }

        return data[tos];
    }

    int size(){
        return tos + 1;
    }

    bool is_empty(){
        if(tos == -1){
            return true;
        } else {
            return false;
        }
    }
};

class two_stack{
private:
    int* data;
    int cap;
    int t1;
    int t2;

public:
    two_stack(int cap){
        this->data = new int[cap];
        this->cap = cap;
        this->t1 = -1;
        this->t2 = cap;
    }

    void push_1(int val){
        if(t1 == cap || t1 == t2){
            cout << "Stack 1 Overflow" << endl;
            return;
        }
        
        t1++;
        data[t1] = val;
    }

    void push_2(int val){
        if(t2 == -1 || t2 == t1){
            cout << "Stack 2 Overflow" << endl;
            return;
        }
        
        t2--;
        data[t2] = val;
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

        data[t2] == 0;
        t2++;
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

    int size_1(){
        return t1 + 1;
    }

    int size_2(){
        return this->cap - t2;
    }

    bool is_empty_1(){
        if(t1 == -1){
            return true;
        }
        else {
            return false;
        }
    }

    bool is_empty_2(){
        if(t2 == cap){
            return true;
        } else {
            return false;
        }
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
    // my_stack ms(5);

    // ms.push(10);
    // ms.push(20);
    // ms.push(30);
    // ms.push(40);
    // ms.push(50);
    // ms.push(60);

    // while(ms.size() > 0){
    //     cout << ms.top() << " ";
    //     ms.pop();
    // }

    // ms.pop();

    // ======================================================== //

    two_stack ms(5);

    ms.push_1(10);
    ms.push_1(20);
    ms.push_2(30);
    ms.push_2(40);
    ms.push_2(50);
    ms.push_1(60);

    // while(ms.size_1() > 0){
    //     cout << ms.top_1() << " ";
    //     ms.pop_1();
    // }

    // cout << endl;

    // while(ms.size_2() > 0){
    //     cout << ms.top_2() << " ";
    //     ms.pop_2();
    // }

    // ms.pop_1();
    // ms.pop_2();

    while(ms.size_1() > 0){
        cout << ms.top_1() << " ";
        ms.pop_1();
    }

    cout << endl;

    while(ms.size_2() > 0){
        cout << ms.top_2() << " ";
        ms.pop_2();
    }

    cout << ms.is_full() << endl;
}