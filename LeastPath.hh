#include "Algo.hh"

class LeastPath : public Algo {
    public:
        LeastPath(int size = 9, bool doLog = false);
        ~LeastPath();
        int getNextMove();
};

