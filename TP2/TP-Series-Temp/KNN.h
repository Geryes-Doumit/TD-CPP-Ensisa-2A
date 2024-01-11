#ifndef KNN_H
#define KNN_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>
#include <stdexcept>
#include <algorithm>
#include "TimeSeriesDataset.h"
#include <unordered_map>

using namespace std;

class KNN {
    private:
        int k;
        string similarityMeasure;

    public:
        KNN(int k, string similarityMeasure): k(k), similarityMeasure(similarityMeasure) {}

        double euclidean_distance(const vector<double>& timeSeries1, const vector<double>& timeSeries2) {
            int size1 = timeSeries1.size();
            int size2 = timeSeries2.size();
            cout << size1 << " " << size2 << endl;
            if (size1 != size2) {
                throw invalid_argument("Time series have different sizes.");
            }

            int size = min(size1, size2);
            double distance = 0;
            for (int i = 0; i < size; i++) {
                distance += pow(timeSeries1[i] - timeSeries2[i], 2);
            }
            distance = sqrt(distance);

            return distance;
        }

        double dtw(const vector<double>& timeSeries1, const vector<double>& timeSeries2) {
            int size1 = timeSeries1.size();
            int size2 = timeSeries2.size();

            vector<vector<double>> matrix = vector<vector<double>>(size2 + 1, vector<double>(size1 + 1, DBL_MAX));
            matrix[0][0] = 0;

            for (int i = 1; i <= size1; i++) {
                for (int j = 1; j <= size2; j++) {
                    double d = pow(timeSeries1[i] - timeSeries2[j], 2);
                    matrix[i][j] = d + min(matrix[i][j-1], matrix[i-1][j-1]);
                }
            }

            return sqrt(matrix[size1][size2]);
        }

        double evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, vector<int>& ground_truth) {
            int correctPredictions = 0;
            double accuracy = 0.0;
            
            

            return 0;
        }

};

#endif