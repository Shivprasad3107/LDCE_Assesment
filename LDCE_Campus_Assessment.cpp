#include <bits/stdc++.h>
using namespace std;

class Rover {
private:
    int xPos, yPos, zPos;
    char orientation;
    char facingDirection;

public:
    Rover(int initialX, int initialY, int initialZ, char initialOrientation) {
        xPos = initialX;
        yPos = initialY;
        zPos = initialZ;
        orientation = initialOrientation;
        facingDirection = orientation;
    }

    void moveForward() {
        if (facingDirection == 'S') {
            yPos -= 1;
        } 
        else if (facingDirection == 'N') {
            yPos += 1;
        } 
        else if (facingDirection == 'E') {
            xPos += 1;
        } 
        else if (facingDirection == 'W') {
            xPos -= 1;
        } 
        else if (facingDirection == 'U') {
            zPos += 1;
        } 
        else if (facingDirection == 'D') {
            zPos -= 1;
        }
    }

    void moveBackward() {
        if (facingDirection == 'N') {
            yPos -= 1;
        } 
        else if (facingDirection == 'S') {
            yPos += 1;
        }
        else if (facingDirection == 'E') {
            xPos -= 1;
        } 
        else if (facingDirection == 'W') {
            xPos += 1;
        }
        else if (facingDirection == 'U') {
            zPos -= 1;
        }
        else if (facingDirection == 'D') {
            zPos += 1;
        }
    }

    void rotateLeft() {
        if (orientation == 'N') {
            orientation = 'W';
            facingDirection = 'W';
        } 
        else if (orientation == 'S') {
            orientation = 'E';
            facingDirection = 'E';
        } 
        else if (orientation == 'E') {
            orientation = 'N';
            facingDirection = 'N';
        } 
        else if (orientation == 'W') {
            orientation = 'S';
            facingDirection = 'S';
        }
    }

    void rotateRight() {
        if (orientation == 'N') {
            orientation = 'E';
            facingDirection = 'E';
        } 
        else if (orientation == 'S') {
            orientation = 'W';
            facingDirection = 'W';
        } 
        else if (orientation == 'E') {
            orientation = 'S';
            facingDirection = 'S';
        } 
        else if (orientation == 'W') {
            orientation = 'N';
            facingDirection = 'N';
        }
    }

    void turnUp() {
        if (facingDirection != 'U') {
            facingDirection = 'U';
        }
    }

    void turnDown() {
        if (facingDirection != 'D') {
            facingDirection = 'D';
        }
    }

    void executeCommands(const vector<char>& commands) {
        for (char command : commands) {
            if (command == 'f') {
                moveForward();
            } 
            else if (command == 'b') {
                moveBackward();
            } 
            else if (command == 'l') {
                rotateLeft();
            } 
            else if (command == 'r') {
                rotateRight();
            } 
            else if (command == 'u') {
                turnUp();
            } 
            else if (command == 'd') {
                turnDown();
            }
        }
    }

    void printPosition() {
        cout << "Final Position: (" << xPos << ", " << yPos << ", " << zPos << ")" << endl;
        cout << "Final Direction: " << facingDirection << endl;
    }
};

int main() {
   Rover rover1(0, 0, 0, 'N');
    vector<char> commands = {'f', 'r', 'u', 'b', 'l'};
    
    rover1.executeCommands(commands);
    rover1.printPosition();
    
    return 0;
}
