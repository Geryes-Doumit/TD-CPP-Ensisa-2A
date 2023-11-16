#include "JumpSearch.h"

int JumpSearch::search(const vector<int>& v, int target) {
    int jumpLength = (int) sqrt(v.size());
    int index = jumpLength;

    numberComparisons = 0;

    while (index < v.size()) {
        numberComparisons++;
        
        if (v[index] > target) {
            for (int i = index - jumpLength; i < index; i++) {
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

    return -1;
}