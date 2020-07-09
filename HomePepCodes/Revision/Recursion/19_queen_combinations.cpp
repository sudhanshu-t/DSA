#include <iostream>
#include <string>
#include <vector>

using namespace std;

void queen_level(vector<int>& boxes, int cb, int cq, int tq, string asf){
    if(cq == tq){
        cout << asf << endl;
        return;
    }
    
    for(int i = cb; i < boxes.size(); i++){
        if(boxes[cb] == 0){
            boxes[cb] = 1;
            queen_level(boxes, i + 1, cq + 1, tq, asf + "b" + to_string(i) + "q" + to_string(cq));
            boxes[cb] = 0;
        }
    }
}

void box_level(int cb, int tb, int qpsf, int tq, string asf){
    if(cb == tb){
        if(qpsf == tq){
            cout << asf << endl;
        }

        return;
    }
    
    box_level(cb + 1, tb, qpsf, tq, asf);
    box_level(cb + 1, tb, qpsf + 1, tq, asf + "b" + to_string(cb) + "q" + to_string(qpsf));
}

int main(int argc, char** argv){
    vector<int> boxes (4, 0);
    // queen_level(boxes, 0, 0, 2, "");
    box_level(0, 4, 0, 2, "");
}