#include <iostream>
using namespace std;

class Robot {
public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move();
    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();
    void turnRight();
    // Clean the current cell.
    void clean();
};

void cleanRoom(Robot& robot) {

}

int main(){
    cleanRoom()
}