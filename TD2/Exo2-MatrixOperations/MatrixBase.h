#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

#ifndef MARTRIXBASE_H
#define MARTRIXBASE_H

template<class T> 
class MatrixBase {
    protected:
        size_t rows, cols;
        vector<vector<T>> data;

    public:
        // Constructor 
        explicit MatrixBase(size_t rows, size_t cols) : rows(rows), cols(cols) 
        {
            data = vector<vector<T>>(rows, vector<T>(cols));    
        }
        
        // printing matrix
        void Display() const 
        {
            int printWidth = 4;

            for (size_t i = 0; i < rows; ++i) 
            {
                for (size_t j = 0; j < cols; ++j) 
                {
                    int newSize = to_string(data[i][j]).size();
                    if ( newSize > printWidth) 
                        printWidth = newSize;
                }
            }
            
            for (size_t i = 0; i < rows; ++i) 
            {
                for (size_t j = 0; j < cols; ++j) 
                {
                    cout << setw(printWidth) << data[i][j] << ",";
                }

                cout << endl;
            }
        }

        T getElement(size_t row, size_t col) {
            return data[row][col];
        };

        void addElement(size_t row, size_t col, T element) {
            data[row][col] = element;
        };

        size_t getRows() {
            return rows;
        };

        size_t getCols() {
            return cols;
        };

        vector<vector<T>> getData() {
            return data;
        };
};

#endif