#include <iostream>
#include <climits>
using namespace std;

class min_stack{
private:
    int* data;
    int tos;
    int cap;

public:
    int min;

    min_stack(int cap){
        data = new int[cap];
        this->cap = cap;
        tos = -1;
        min = INT_MAX;
    }

    bool is_full(){
        if(tos == cap - 1){
            return true;
        } else {
            return false;
        }
    }

    bool is_empty(){
        if(tos == -1){
            return true;
        } else {
            return false;
        }
    }

    void push(int val){
        if(!is_full()){
            tos++;
            if(val < min){
                data[tos] = 2 * val - min;
                min = val;
            } else {
                data[tos] = val;
            }
        } else {
            cout << "Stack Overflow" << endl;
            return;
        }
    }

    int top(){
        if(is_empty()){
            return -1;
        } else {
            if(data[tos] < min){
                return min;
            } else {
                return data[tos];
            }
        }
    }

    void pop(){
        if(is_empty()){
            cout << "Stack Underflow" << endl;
            return;
        } else {
            if(data[tos] < min){
                min = 2 * min - data[tos];
                data[tos] = 0;
            } else {
                data[tos] = 0;
            }

            tos--;
        }
    }
};

int main(int argc, char** argv){
    min_stack ms(6);

    ms.push(10);
    ms.push(14);
    cout << ms.min << endl;
    ms.push(7);
    cout << ms.min << endl;
    ms.push(8);
    ms.push(2);
    cout << ms.min << endl;
    ms.push(12);
    ms.push(100);

    while(!ms.is_empty()){
        cout << ms.min << endl;
        ms.pop();
    }

    ms.pop();
}