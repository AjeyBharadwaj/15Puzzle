#include "Algo.hh"
#include "cstdio"

Algo::Algo(string name, int size, bool doLog) {
    int i, j, k, l, val;    

    this->doLog = doLog;
    log("Creating new Algo : " + name + " , with size : ");
    algoName = name;
    this->size = size;
    board = new int*[size];
    for(i = 0; i < size; i++) {
        board[i] = new int[size];
    }

    setWidthModifier();
    lastMove = UNDEFINED;

    board[0][0] = 11;
    board[0][1] = 6;
    board[0][2] = 0;
    board[0][3] = 8;
    board[1][0] = 15;
    board[1][1] = 4;
    board[1][2] = 12;
    board[1][3] = 7;
    board[2][0] = 5;
    board[2][1] = 9;
    board[2][2] = 3;
    board[2][3] = 2;
    board[3][0] = 1;
    board[3][1] = 14;
    board[3][2] = 10;
    board[3][3] = 13;

    ePos.x = 0;
    ePos.y = 2;

    /*
    srand(time(NULL));

    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++) 
            board[i][j] = 0;

    
    val = 1;
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++) {
            board[i][j] = val++;
    }

    ePos.x = size-1;
    ePos.y = size-1;
    board[size-1][size-1] = 0;    

    setWidthModifier();
    */
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

bool Algo::isDone() {
    int i;
    int j;

    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            if (board[i][j] != (i*size+j+1))
                goto NOTDONE;
    NOTDONE:
    if (i == (size-1) && j == (size-1)) {
        log("Done!!!");
        return true;
    }

    return false;
}

bool Algo::move() {
    // Find available moves.
    // Calculate score.
    // Determine move.
    int tmp_score;
    int score = INT_MAX;
    Mov M;

    tmp_score = findScore(LEFT);
    if (tmp_score > score && lastMove != RIGHT) {
        score = tmp_score;
        M = LEFT;
    }

    tmp_score = findScore(RIGHT);
    if (tmp_score < score && lastMove != LEFT) {
        score = tmp_score;
        M = RIGHT;
    }

    tmp_score = findScore(UP);
    if (tmp_score < score && lastMove != DOWN) {
        score = tmp_score;
        M = UP;
    }

    tmp_score = findScore(DOWN);
    if (tmp_score < score && lastMove != UP) {
        score = tmp_score;
        M = DOWN;
    }

    if (score == INT_MAX) {
        log("No possible moves");
        return false;
    }

    switch(M) {
        case LEFT:
            board[ePos.x][ePos.y] = board[ePos.x][ePos.y-1]; 
            board[ePos.x][ePos.y-1] = 0;
            ePos.y = ePos.y-1;
            lastMove = LEFT;

            break;
        case RIGHT:
            board[ePos.x][ePos.y] = board[ePos.x][ePos.y+1];
            board[ePos.x][ePos.y+1] = 0;
            ePos.y = ePos.y+1;
            lastMove = RIGHT;

            break;
        case UP:
            board[ePos.x][ePos.y] = board[ePos.x-1][ePos.y];
            board[ePos.x-1][ePos.y] = 0;
            ePos.x = ePos.x-1;
            lastMove = UP;

            break;
        case DOWN:
            board[ePos.x][ePos.y] = board[ePos.x+1][ePos.y];
            board[ePos.x+1][ePos.y] = 0;
            ePos.x = ePos.x+1;
            lastMove = DOWN;

            break;
    }

    return true;
}

