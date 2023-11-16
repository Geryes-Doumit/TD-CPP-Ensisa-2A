#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include "SearchingAlgorithm.h"

class LinearSearch : public SearchingAlgorithm {
    public:
        int search(const vector<int>&, int) override;
};

#endif