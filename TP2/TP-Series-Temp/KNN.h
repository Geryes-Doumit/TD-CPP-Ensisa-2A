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
            
            for (size_t i = 0; i < testData.getNumberOfSamples(); ++i) {
                vector<pair<double, int>> distances;

                for (size_t j = 0; j < trainData.getNumberOfSamples(); ++j) {
                    double distance;
                    if (similarityMeasure == "euclidean_distance") {
                        distance = euclidean_distance(testData.getData(i), trainData.getData(j));
                    } 
                    else if (similarityMeasure == "dtw") {
                        distance = dtw(testData.getData(i), trainData.getData(j));
                    } 
                    else {
                        throw invalid_argument("Invalid term for similarity");
                    }
                    distances.emplace_back(distance, trainData.getLabel(j));
                }

                sort(distances.begin(), distances.end());

                unordered_map<int, int> labelCounts;
                for (int neighbor = 0; neighbor < k && neighbor < distances.size(); ++neighbor) {
                    labelCounts[distances[neighbor].second]++;
                }

                int predictedLabel = max_element(labelCounts.begin(), labelCounts.end(),
                                                 [](const pair<int, int>& a, const pair<int, int>& b) 
                                                     { return a.second < b.second; }
                                                )->first;

                if (predictedLabel == ground_truth[i]) {
                    ++correctPredictions;
                }
            }

            accuracy = (double) correctPredictions / testData.getNumberOfSamples();

            return accuracy;
        }

};

#endif