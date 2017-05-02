#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Mov {
    UNDEFINED,
    LEFT,
    RIGHT,
    UP,
    DOWN    
};

struct Movement {
    int x;
    int y;
    Mov M;
};
typedef struct Movement Movement;

typedef struct Position {
    int x;
    int y;
}Position;

class Algo {
    public:
        Algo(string name = "Undefined", int size = 9, bool doLog = false);
        ~Algo();
        
        void printBoard();
        bool move(Movement M);
        bool move();
        bool isDone();
        void log(string log);
        int getWidthModifier();
        virtual int getNextMove() = 0;
        
    private:
        string algoName;
        bool doLog;
        int widthModifier;
        struct Movement possibleMove;
        void setWidthModifier();
        void printLine();
        virtual int findScore(Mov M) = 0;

    protected:
        int **board;
        Position ePos;
        int size;
        Mov lastMove;
};

