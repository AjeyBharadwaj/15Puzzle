#include <iostream>
#include "LeastPath.hh"

using namespace std;

int main(int argc, char *argv[]) {
    LeastPath LP(4, true);
    LP.printBoard();
    while(LP.isDone() == false) {
        LP.move();
        LP.printBoard();
        int z;
        cin >> z;
    }
}


