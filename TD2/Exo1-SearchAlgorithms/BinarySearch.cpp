#include "BinarySearch.h"

int BinarySearch::search(const vector<int>& v, int target) {
    int startIndex = 0;
    int endIndex = v.size() - 1;

    int midIndex;
    numberComparisons = 0;

    while (endIndex > startIndex) {
        midIndex =  (int) ( (startIndex + endIndex) / 2 );
        int mid = v[midIndex];
        
        numberComparisons++;
        if (mid == target) return midIndex;
        
        if (mid < target) {
            startIndex = midIndex + 1;
        }
        else {
            endIndex = midIndex - 1;
        }
    }

    return -1;
}