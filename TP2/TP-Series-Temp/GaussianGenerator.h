#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include "TimeSeriesGenerator.h"

using namespace std;

#ifndef GAUSS_GENERATOR_H
#define GAUSS_GENERATOR_H

class GaussianGenerator : public TimeSeriesGenerator {
    private:
        double mean;
        double std;

    public:
        GaussianGenerator(double mean, double std, int seed) : TimeSeriesGenerator(seed) {
            this->mean = mean;
            this->std = std;
        }

        GaussianGenerator(double mean, double std) : TimeSeriesGenerator() {
            this->mean = mean;
            this->std = std;
        }

        GaussianGenerator() : TimeSeriesGenerator() {
            this->mean = 0;
            this->std = 1;
        }

        vector<double> generateTimeSeries(int length) {
            vector<double> timeSeries;
            srand(this->seed);
            for (int i = 0; i < length; i++) {
                double u1 = (double) rand() / RAND_MAX;
                double u2 = (double) rand() / RAND_MAX;
                double z = (double) (sqrt(-2.0 * log(u1)) * cos(2 * M_PI * u2) ) + (sqrt(-2.0 * log(u1)) * sin(2 * M_PI * u2)) / 2;
                timeSeries.push_back(this->mean + this->std * z);
            }
            return timeSeries;
        }
};

#endif