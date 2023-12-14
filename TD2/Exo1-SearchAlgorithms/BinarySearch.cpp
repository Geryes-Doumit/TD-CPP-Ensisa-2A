#include "BinarySearch.h"

int BinarySearch::search(const vector<int>& v, int target) {
    int startIndex = 0;
    int endIndex = v.size() - 1;

    int midIndex;
    numberComparisons = 0;

    while (endIndex >= startIndex) {
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

int BinarySearch::searchRecursive(const vector<int> &v, int target, int startIndex, int endIndex) {
    if (endIndex < startIndex) return -1;

    int midIndex =  (int) ( (startIndex + endIndex) / 2 );
    int mid = v[midIndex];

    numberComparisons++;
    if (mid == target) 
        return midIndex;
    
    if (mid < target) 
        return searchRecursive(v, target, midIndex + 1, endIndex);
    
    else 
        return searchRecursive(v, target, startIndex, midIndex - 1);
}