#include <iostream>
using namespace std;

enum Mov {
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
        int size;
        int **board;
        bool doLog;
        int widthModifier;
        struct Movement possibleMove;
        void setWidthModifier();
        void printLine();
};

