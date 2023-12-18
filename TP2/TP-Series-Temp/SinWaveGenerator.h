#include "TimeSeriesGenerator.h"
#include <cmath>

#ifndef SIN_GENERATOR_H
#define SIN_GENERATOR_H

class SinWaveGenerator : public TimeSeriesGenerator {
    private:
        double amplitude;
        double frequency;
        double phase;

    public:
        SinWaveGenerator(double amplitude, double frequency, double phase, int seed) : TimeSeriesGenerator(seed) {
            this->amplitude = amplitude;
            this->frequency = frequency;
            this->phase = phase;
        }

        SinWaveGenerator(double amplitude, double frequency, double phase) : TimeSeriesGenerator() {
            this->amplitude = amplitude;
            this->frequency = frequency;
            this->phase = phase;
        }

        SinWaveGenerator() : TimeSeriesGenerator() {
            this->amplitude = 1;
            this->frequency = 1;
            this->phase = 0;
        }

        vector<double> generateTimeSeries(int length) {
            vector<double> timeSeries;
            srand(this->seed);
            for (int i = 0; i < length; i++) {
                timeSeries.push_back(this->amplitude * sin(this->frequency * i + this->phase));
            }
            return timeSeries;
        }
};

#endif