#ifndef JUMPS_SEARCH_H
#define JUMPS_SEARCH_H

#include "SearchingAlgorithm.h"
#include <cmath>

class JumpSearch : public SearchingAlgorithm {
    public:
        int search(const vector<int>&, int) override;
};

#endif