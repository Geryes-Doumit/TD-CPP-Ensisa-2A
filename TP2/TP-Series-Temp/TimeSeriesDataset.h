#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>

using namespace std;

#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

class TimeSeriesDataset {
    private:
        bool znormalise;
        bool isTrain;
        vector<vector<double>> data;
        vector<int> labels;
        int maxlength;
        int numberOfSamples;

    public:
        int getNumberOfSamples() const {
            return numberOfSamples;
        }

        int getMaxLength() const {
            return maxlength;
        }

        vector<double> getData(int i) const {
            return data[i];
        }

        int getLabel(int i) const {
            return labels[i];
        }

    public:
        TimeSeriesDataset(bool znormalise, bool isTrain) {
            this->znormalise = znormalise;
            this->isTrain = isTrain;
            numberOfSamples = 0;
            maxlength = 0;
        }

        void addTimeSeries(vector<double> timeSeries, int label) {
            if (this->znormalise) {
                this->normalise(timeSeries);
            }
            this->data.push_back(timeSeries);
            if (isTrain) 
                this->labels.push_back(label);
            
            if (timeSeries.size() > this->maxlength) {
                this->maxlength = timeSeries.size();
            }
            this->numberOfSamples++;
        }

        void addTimeSeries(vector<double> timeSeries) {
            if (this->znormalise) {
                this->normalise(timeSeries);
            }
            this->data.push_back(timeSeries);
            if (timeSeries.size() > this->maxlength) {
                this->maxlength = timeSeries.size();
            }
            this->numberOfSamples++;
        }

        double getMean(vector<double> timeSeries) {
            double mean = 0;
            for (int i = 0; i < timeSeries.size(); i++) {
                mean += timeSeries[i];
            }
            mean /= timeSeries.size();
            return mean;
        }

        double getStd(vector<double> timeSeries) {
            double mean = this->getMean(timeSeries);
            double std = 0;
            for (int i = 0; i < timeSeries.size(); i++) {
                std += pow(timeSeries[i] - mean, 2);
            }
            std /= timeSeries.size();
            std = sqrt(std);
            return std;
        }

        void normalise(vector<double>& timeSeries) {
            double mean = this->getMean(timeSeries);
            double std = this->getStd(timeSeries);
            for (int i = 0; i < timeSeries.size(); i++) {
                timeSeries[i] = (timeSeries[i] - mean) / std;
            }
        }
};

#endif