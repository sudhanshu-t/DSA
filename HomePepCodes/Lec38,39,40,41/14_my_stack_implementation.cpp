#include <iostream>

using namespace std;

class my_stack{
private:
    int* data;
    int tos;
    int cap;

public:
    my_stack(int cap){
        data = new int[cap];
        this->cap = cap;
        tos = -1;
    }

    void push(int val){
        if(tos == cap - 1){
            cout << "Stack Overflow" << endl;
            return;
        }
        
        tos++;
        data[tos] = val;
    }

    int top(){
        if(tos == -1){
            return -1;
        }
        
        return data[tos];
    }

    void pop(){
        if(tos == -1){
            cout << "Stack Underflow" << endl;
            return;
        }

        data[tos] = 0;
        tos--;
    }

    int size(){
        return tos + 1;
    }

    bool is_empty(){
        return tos == -1;
    }

    bool is_full(){
        return tos == cap - 1;
    }
};

int main(int argc, char** argv){
    my_stack ms(5);

    ms.push(10);
    ms.push(20);
    ms.push(30);
    ms.push(40);
    ms.push(50);
    ms.push(60);

    while(ms.size() > 0){
        cout << ms.top() << " ";
        ms.pop();
    }

    ms.pop();
}