#include "LeastPath.hh"

LeastPath::LeastPath(int size, bool doLog) : Algo("LeastPath", size, doLog) {
}

LeastPath::~LeastPath() {

}

int LeastPath::getNextMove() {
    return -1;
}

int LeastPath::getScore() {
    int i, j;
    int score = 0;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            if (board[i][j] != 0) {
                score += (i*size+j+1) - board[i][j];
            }
        }
    }
    return score;
}

int LeastPath::findScore(Mov M) {
    int score;
    Position fromPos, toPos;
    fromPos = ePos;

    switch(M) {
        case LEFT:
            if (ePos.y == 0)
                return INT_MAX;

            toPos.x = ePos.x;
            toPos.y = ePos.y-1;

            break;
        case RIGHT:
            if (ePos.y == (size-1))
                return INT_MAX;

            toPos.x = ePos.x;
            toPos.y = ePos.y+1;

            break;
        case UP:
            if (ePos.x == 0)
                return INT_MAX;

            toPos.x = ePos.x-1;
            toPos.y = ePos.y;

            break;
        case DOWN:
            if (ePos.x == (size-1))
                return INT_MAX;

            toPos.x = ePos.x+1;
            toPos.y = ePos.y;

            break;
    }

    board[fromPos.x][fromPos.y] = board[toPos.x][toPos.y];
    board[toPos.x][toPos.y] = 0;

    score = getScore();

    board[toPos.x][toPos.y] = board[fromPos.x][fromPos.y];
    board[fromPos.x][fromPos.y] = 0;

    return score;
}


