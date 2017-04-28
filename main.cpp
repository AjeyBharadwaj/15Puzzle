#include <iostream>
#include "LeastPath.hh"

using namespace std;

int main(int argc, char *argv[]) {
    LeastPath LP(5, false);
    LP.printBoard();
    return 0;
    while(LP.isDone() == false) {
        LP.move();
        LP.printBoard();
    }
}


