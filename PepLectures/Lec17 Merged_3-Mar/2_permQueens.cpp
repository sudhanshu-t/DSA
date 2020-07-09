#include <iostream>
#include <string>

using namespace std;

void printPerm(int cq, bool boxes[], string asf, int tq, int tb){
    if(cq > tq){
        cout << asf << endl;
        return;
    }

    for(int i = 0; i < tb; i++){
        if(boxes[i] == false){
            boxes[i] = true;
            printPerm(cq+1, boxes, asf + "b" + to_string(i) + "q" + to_string(cq) + " ", tq, tb);

            boxes[i] = false;
        }
    }

    return;
}

int main(int argc, char** argv){
    bool boxes[4];
    printPerm(1, boxes, "", 2, 4);
}