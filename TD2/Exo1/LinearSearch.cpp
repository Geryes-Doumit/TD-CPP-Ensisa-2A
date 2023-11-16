#include "LinearSearch.h"

int LinearSearch::search(const vector<int>& v, int x) {
    numberComparisons = 0;

    for (int i = 0; i < v.size(); i++) {
        numberComparisons++;
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}