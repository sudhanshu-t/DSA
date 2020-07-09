#include <iostream>
using namespace std;

// int* wfun(){
//     int x = 10;
//     return &x;
// }

// void fun(int* x){
//     int y = 20;
    
//     int d = (&y) - (x);

//     if(d < 0){
//         cout << "Top Down" << endl;
//     } else {
//         cout << "Bottom Up" << endl;
//     }

//     cout << &y << " " << x << endl;

// }

// int x = 9;
// int* rfun_g(){
//     return &x;
// }

// int* rfun_s(){
//     static int x = 10;

//     return &x;
// }

// void nloop(){
//     int y = 10;
//     y++;

//     cout << y << endl;
// }

// void sloop2(){
//     static int y = 10;
//     cout << y << endl;
//     y++;
// }

// void sloop1(){
//     static int y = 30;
//     cout << y << endl;
//     y++;
// }

// void fun(int* a){
//     cout << sizeof(a) / sizeof(int) << endl;
// }

int main(int argc, char** argv){

////// Array Decay
    // int arr[] = {1,2,3,4};
    // fun(arr);

    // cout << arr++ << endl; // error - lvalue required as increment operand

////// Arrays and Pointers - Part 1 (Pointer to an Array)

    // int arr[5] = {1,2,3,4,5};
    // int* p1 = arr;
    // int* p2 = &arr[0];

    // Pointer to the whole array
    // int (*p3)[5] = &arr; // P3 is a pointer to a bunch of 5 ints here. ie complete array arr of 20 bytes.

    // p3 will jump by 5*4 ie 20 bytes if p3 + 1 is written.
    // cout << &arr[0] << *p3 + 1 << endl;

    // cout << *p3 << " " << &arr[0] <<  endl; // *p3 = *&arr = arr = &arr[0]

////// Typecasting int* to int (Doubt - Not working, giving error: cast from int* to int loses precision)  
    // int i = 10;
    // int j = (int)&i;

    // cout << j << endl;

////// Pointer Arithmetic
//     int i = 10;
//     short int j = 20;
//     long long int k = 30;

//     int* p1 = &i;
//     short int* p2 = &j;
//     long long int* p3 = &k;

//     // cout << sizeof(long long int*) << endl;

//     // Multiply by sizeof(int)
//     cout << p1 << " " << p1 + 5 << endl;
//     cout << p2 << " " << p2 + 5 << endl;
//     cout << p3 << " " << p3 + 5 << endl;

//     // Divide by sizeof
//     int* p11 = p1 + 5;
//     short int* p22 = p2 + 5;
//     long long int* p33 = p3 + 5;

//     cout << (char*)p11 - (char*)p1 << endl;
//     cout << p22 - p2 << endl;
//     cout << p33 - p3 << endl;

    // cout << sizeof(int*) << endl;

////// Loops using normal vs static variables

    // for(int i = 0; i < 5; i++){
    //     nloop();
    // }

    // for(int i = 0; i < 5; i++){
    //     sloop1();
    //     sloop2();
    // }

////// Static variables 

    // int* p = rfun_s();
    // cout << p << endl;
    // cout << *p << endl;

    //cout << x << endl;

////// Making wfun right by using global variable
    // int* p = rfun_g();
    // cout << p << endl;
    // cout << *p << endl;

    // cout << x << endl;


////// Checking stack ordering  ===========================================
    // int x = 10;
    // cout << &x << endl;
    // fun(&x);

    // int x = 10;
    // int y = 20;
    
    // int d = (&y) - (&x);

    // if(d < 0){
    //     cout << "Top Down" << endl;
    // } else {
    //     cout << "Bottom Up" << endl;
    // }

    // cout << &y << " " << &x << endl;
    
    // int* p = wfun();

    // cout << p << endl;
    // cout << *p << endl;
    
    
////// Basic * & ** operations  =============================================    
    // int i = 10;
    // int* p = &i;
    // int** q = & p;

    // cout << *&*&*&q << endl;
    // cout << q << endl;

    // cout << i << endl;
    // cout << &i << endl;
    // cout << p << endl;
    // cout << &p << endl;
    // cout << q << endl;
    // cout << *p << endl;
    // cout << *q << endl;
    // cout << **q << endl;


////// Some typecasting experiments  ==========================================
    // char c = 10;
    // char* pc = &c;

    // int** q = (int**)&pc;

    // cout << pc << endl;
    // cout << &pc << endl;
    // cout << q << endl;
    // cout << *q << endl;
    // cout << *pc << endl;



    return 0;
}