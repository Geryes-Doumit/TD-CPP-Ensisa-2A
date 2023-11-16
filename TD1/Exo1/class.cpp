#include <iostream>
using namespace std;

#include "class.h"

my_class::my_class() {
    message = "Hello World !";
}

my_class::my_class(string message)
    : message(message) 
{}

void my_class::printMessage() {
    cout << message << endl;
}

void my_class::setMessage(string message) {
    this->message = message;
}