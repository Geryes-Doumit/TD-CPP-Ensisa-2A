#include "JumpSearch.h"

int JumpSearch::search(const vector<int>& v, int target) {
    int size = v.size();
    int jumpLength = (int) sqrt(size);
    int index = jumpLength;

    numberComparisons = 0;

    while (index < size) {
        numberComparisons++;
        
        if (v[index] > target) {
            for (int i = index - jumpLength; i < index; ++i) {
                numberComparisons++;
                if (v[i] == target) {
                    return i;
                }
            }
            return -1;
        }
        else {
            index += jumpLength;
        }
    }

    index -= jumpLength;
    if (index < size) {
        for (int i = index; i < size; ++i) {
            numberComparisons++;
            if (v[i] == target) {
                return i;
            }
        }
    }

    return -1;
}