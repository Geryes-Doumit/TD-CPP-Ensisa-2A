#include "SearchingAlgorithm.h"

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0) {}

void SearchingAlgorithm::displaySearchResults(ostream& out, int results, int target) const {
    totalSearch++;

    if (results == -1) {
        out << "The target " << target << " was not found." << endl;
    } else {
        out << "The target " << target << " was found at index " << results << "." << endl;

        totalComparisons += numberComparisons;
        averageComparisons = (double) totalComparisons / totalSearch;
        out << "It took " << numberComparisons << " comparisons to find the target." << endl;
    }

    out << endl;
}