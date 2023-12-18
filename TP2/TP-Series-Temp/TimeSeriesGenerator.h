#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

#ifndef TIMESERIES_H
#define TIMESERIES_H

class TimeSeriesGenerator {
    protected:
        int seed;

    public:
        TimeSeriesGenerator(int seed) {
            this->seed = seed;
        }

        TimeSeriesGenerator() {
            this->seed = time(NULL);
        }

        virtual vector<double> generateTimeSeries(int length) = 0;
        
        void static printTimeSeries(const vector<double>& timeSeries) {
            for (int i = 0; i < timeSeries.size(); i++) {
                cout << timeSeries[i] << " ";
            }
            cout << endl;
        }
};

#endif