#ifndef CLASS_H
#define CLASS_H

#include <iostream>
using namespace std;

class my_class {
    private:
        string message;

    public :
        my_class();
        my_class(string message);
        void printMessage();
        void setMessage(string message);
};

#endif