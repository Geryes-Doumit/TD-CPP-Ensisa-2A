#include "MatrixBase.h"
#include <cmath>

#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

template<class num>
class MatrixNumerical : public MatrixBase<num> {

    using MatrixBase<num>::MatrixBase;

    private:
        size_t rows, cols;

    public:

        MatrixNumerical(size_t rows, size_t cols) : MatrixBase<num>(rows, cols) {
            this->rows = rows;
            this->cols = cols;
        };

        static MatrixNumerical<num> getIdentity(int size) {
            MatrixNumerical<num> identity(size, size);

            for (size_t i = 0; i < size; ++i) {
                for (size_t j = 0; j < size; ++j) {
                    if (i == j) {
                        identity.addElement(i, j, 1);
                    }
                    else {
                        identity.addElement(i, j, 0);
                    }
                }
            }

            return identity;
        };


        double getDeterminant() const {
            double det;

            if (rows != cols) {
                cout << "Matrix is not square" << endl;
                return 0;
            }
            if (rows == 1) {
                return MatrixBase<num>::data[0][0];
            } 
            else if (rows == 2) {
                det = (MatrixBase<num>::data[0][0] * MatrixBase<num>::data[1][1] 
                    - MatrixBase<num>::data[0][1] * MatrixBase<num>::data[1][0]);
                
                return det;
            }
            else {
                for (size_t i = 0; i < rows; ++i) {
                    MatrixNumerical<num> submatrix(rows-1, cols-1);

                    for (size_t j = 1; j < rows; ++j) {
                        for (size_t k = 0; k < cols; ++k) {
                            if (k < i) {
                                submatrix.addElement(j-1, k, MatrixBase<num>::data[j][k]);
                            }
                            else if (k > i) {
                                submatrix.addElement(j-1, k-1, MatrixBase<num>::data[j][k]);
                            }
                        }
                    }

                    det += pow(-1, i) * MatrixBase<num>::data[0][i] * submatrix.getDeterminant();
                }

                return det;
            }
        };

        MatrixNumerical<num> getCoFactor() const {
            if (rows != cols) {
                cout << "Matrix is not square" << endl;
                return MatrixNumerical<num>(0, 0);
            }

            MatrixNumerical<num> coFactor(rows, cols);
            
            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < cols; ++j) {
                    MatrixNumerical<num> submatrix(rows-1, cols-1);

                    for (size_t k = 0; k < rows; ++k) {
                        for (size_t l = 0; l < cols; ++l) {
                            if (k != i && l != j) {
                                if (k < i && l < j) {
                                    submatrix.addElement(k, l, MatrixBase<num>::data[k][l]);
                                }
                                else if (k < i && l > j) {
                                    submatrix.addElement(k, l-1, MatrixBase<num>::data[k][l]);
                                }
                                else if (k > i && l < j) {
                                    submatrix.addElement(k-1, l, MatrixBase<num>::data[k][l]);
                                }
                                else if (k > i && l > j) {
                                    submatrix.addElement(k-1, l-1, MatrixBase<num>::data[k][l]);
                                }
                            }
                        }
                    }

                    coFactor.addElement(i, j, pow(-1, i+j) * submatrix.getDeterminant());
                }
            }

            return coFactor;
        }

        MatrixNumerical<num> getInverse() const {
            if (rows != cols) {
                cout << "Matrix is not square" << endl;
                return MatrixNumerical<num>(0, 0);
            }

            MatrixNumerical<num> inverse(rows, cols);

            double det = getDeterminant();

            if (det == 0) {
                cout << "Matrix is not invertible" << endl;
                return MatrixNumerical<num>(0, 0);
            }

            MatrixNumerical<num> coFactor = getCoFactor();

            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < cols; ++j) {
                    inverse.addElement(i, j, coFactor.data[j][i] / det);
                }
            }

            return inverse;
        };

        friend MatrixNumerical<num> operator + (const MatrixNumerical<num> &a, const MatrixNumerical<num> &b) {
            if (a.rows != b.rows || a.cols != b.cols) {
                cout << "Matrices are not of the same size" << endl;
                return MatrixNumerical<num>(0,0);
            }

            MatrixNumerical<num> sum(a.rows, a.cols);

            for (size_t i = 0; i < a.rows; ++i) {
                for (size_t j = 0; j < a.cols; ++j) {
                    sum.addElement(i, j, a.data[i][j] + b.data[i][j]);
                }
            }

            return sum;
        };

        friend MatrixNumerical<num> operator - (const MatrixNumerical<num> &a, const MatrixNumerical<num> &b) {
            if (a.rows != b.rows || a.cols != b.cols) {
                cout << "Matrices are not of the same size" << endl;
                return MatrixNumerical<num>(0,0);
            }

            MatrixNumerical<num> diff(a.rows, a.cols);

            for (size_t i = 0; i < a.rows; ++i) {
                for (size_t j = 0; j < a.cols; ++j) {
                    diff.addElement(i, j, a.data[i][j] - b.data[i][j]);
                }
            }

            return diff;
        };

        friend MatrixNumerical<num> operator * (const MatrixNumerical<num> &a, const MatrixNumerical<num> &b) {
            if (a.cols != b.rows) {
                cout << "Matrices are not compatible for multiplication" << endl;
                return MatrixNumerical<num>(0,0);
            }

            MatrixNumerical<num> product(a.rows, b.cols);

            for (size_t i = 0; i < a.rows; ++i) {
                for (size_t j = 0; j < b.cols; ++j) {
                    for (size_t k = 0; k < a.cols; ++k) {
                        product.addElement(i, j, product.data[i][j] + a.data[i][k] * b.data[k][j]);
                    }
                }
            }

            return product;
        };
        
        friend MatrixNumerical<num> operator * (const num &b, const MatrixNumerical<num> &a) {
            MatrixNumerical<num> product(a.rows, a.cols);

            for (size_t i = 0; i < a.rows; ++i) {
                for (size_t j = 0; j < a.cols; ++j) {
                    product.addElement(i, j, a.data[i][j] * b);
                }
            }

            return product;
        };

        friend MatrixNumerical<num> operator / (const MatrixNumerical<num> &a, const MatrixNumerical<num> &b) {
            return a*b.getInverse();
        };
};

#endif