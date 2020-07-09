#include <iostream>
#include <string>

using namespace std;

int counter = 0;

void qp_2n(int bno, int tb, bool itqp[], int cq, int tq, string asf) {
    if (bno == tb) {
        if (cq == tq) {
            cout << asf << endl;
            counter++;
        }
        return;
    }

    qp_2n(bno + 1, tb, itqp, cq, tq, asf);

    for (int i = 0; i < tq; i++) {
        if (!itqp[i]) {
            itqp[i] = true;
            qp_2n(bno + 1, tb, itqp, cq + 1, tq, asf + "B" + to_string(bno) + "Q" + to_string(i) + " ");
            itqp[i] = false;
        }
    }
}

int main(int argc, char** argv){
    bool itqp[] = {false};

    qp_2n(0, 3, itqp, 0, 2, "");

    cout << counter << endl;
}