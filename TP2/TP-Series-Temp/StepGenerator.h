#include "TimeSeriesGenerator.h"
#include <cmath>

#ifndef STEP_GENERATOR_H
#define STEP_GENERATOR_H

class StepGenerator : public TimeSeriesGenerator {
    public:
        virtual vector<double> generateTimeSeries(int length) {
            vector<double> timeSeries;
            timeSeries.push_back(0);
            
            for (int i = 1; i < length; i++) {
                // 50% chance of choosing the same value as the previous one
                if (rand() % 2 == 0) {
                    timeSeries.push_back(timeSeries[i - 1]);
                } 
                // 50% chance of choosing a random value between 0 and 100
                else {
                    timeSeries.push_back(rand()%101);
                }
            }

            return timeSeries;
        }
};

#endif