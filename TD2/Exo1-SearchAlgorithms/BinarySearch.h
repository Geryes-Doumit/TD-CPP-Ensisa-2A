#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "SearchingAlgorithm.h"

class BinarySearch : public SearchingAlgorithm {
    public:
        int search(const vector<int>&, int) override;

        int searchRecursive(const vector<int>&, int, int, int);
};

#endif