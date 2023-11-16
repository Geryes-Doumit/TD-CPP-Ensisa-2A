#include <vector>
#include <iostream>
#ifndef SEARCHING_ALGORITHM_H
#define SEARCHING_ALGORITHM_H

using namespace std;

class SearchingAlgorithm {
    public:
        int numberComparisons;

        static int totalComparisons;
        static int totalSearch;
        static double averageComparisons;

        SearchingAlgorithm();

        virtual int search (const vector<int>&, int) = 0;

        void displaySearchResults(ostream&, int, int) const;
};

#endif