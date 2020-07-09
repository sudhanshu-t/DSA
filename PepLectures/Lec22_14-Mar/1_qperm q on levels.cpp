#include <iostream>
#include <string>

using namespace std;

void qperm_qOnLevel(bool boxes[], int tb, int tq, int qpsf, string asf){
    if(qpsf == tq){
        cout << asf << endl;
        return;
    }
    
    for(int i = 0; i < tb; i++){
        if(boxes[i] == false){
            boxes[i] = true;
            qperm_qOnLevel(boxes, tb, tq, qpsf+1, asf + "b" + to_string(i) + "q" + to_string(qpsf) + " ");
            boxes[i] = false;
        }
    }
}

void qcomb_qOnLevel(bool boxes[], int tb, int tq, int cb, int qpsf, string asf){
    if(qpsf == tq){
        cout << asf << endl;
        return;
    }
    
    for(int i = cb; i < tb; i++){
        if(boxes[i] == false){
            boxes[i] = true;
            qcomb_qOnLevel(boxes, tb, tq, i+1, qpsf+1, asf + "b" + to_string(i) + "q" + to_string(qpsf) + " ");
            boxes[i] = false;
        }
    }
}

void qperm_bOnLevel(bool boxes[], int bno, int qpsf, int tb, int tq, string asf){
    if(bno == tb){
        cout << "td" << endl;
        if(qpsf == tq){
            cout << asf << endl;
        }
        return;
    }

    if(boxes[bno] = false){
        boxes[bno] = true;
        qperm_bOnLevel(boxes, bno+1, qpsf+1, tb, tq, asf + "b" + to_string(bno) + "q" + to_string(qpsf) + " ");
        boxes[bno] = false;

        qperm_bOnLevel(boxes,bno+1, qpsf, tb, tq, asf);
    }  
    
    qperm_bOnLevel(boxes,bno+1, qpsf, tb, tq, asf);
}

int main(int argc, char** argv){
    bool boxes[4];

    // qperm_qOnLevel(boxes, 4, 2, 0, "");
    // qcomb_qOnLevel(boxes, 4, 2, 0, 0, "");
    qperm_bOnLevel(boxes, 0, 0, 4, 2, "");
}