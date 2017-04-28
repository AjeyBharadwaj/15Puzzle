#include "Algo.hh"
#include "cstdio"

Algo::Algo(string name, int size, bool doLog) {
    int i, j, val;    

    this->doLog = doLog;
    log("Creating new Algo : " + name + " , with size : ");
    algoName = name;
    this->size = size;
    board = new int*[size];
    for(i = 0; i < size; i++) {
        board[i] = new int[size];
    }

    val = 1;
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            board[i][j] = val++;
    board[size-1][size-1] = 0;    

    setWidthModifier();

}

Algo::~Algo() {
    log("Deleting the object");
}

void Algo::log(string log) {
    if (doLog) {
        cout << log << endl;
    }
}

void Algo::printLine() {
    int i;
    for(i = 0; i < size*5+1; i++) {
        cout << "-";
    }
    cout <<endl;
}

void Algo::setWidthModifier() {
    if (size < 10)
        widthModifier = 1;
    else if (size < 100)
        widthModifier = 2;
    else if (size < 1000)
        widthModifier = 3;
}

int Algo::getWidthModifier() {
    return widthModifier;
}

void Algo::printBoard() {
    int i, j;

    printLine();

    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            //TODO : Replace printf with cout
            //TODO : Use Set and Get widthModifier.
            if (board[i][j] != 0)
                printf("| %2d ", board[i][j]);
            else 
                printf("|    ");
        }
        cout << "|" << endl;
        printLine();
    }
}

