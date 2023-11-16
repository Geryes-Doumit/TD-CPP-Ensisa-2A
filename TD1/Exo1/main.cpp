#include <iostream>
using namespace std;

#include "printString.h"
#include "class.h"

int main(int argc, char* argv[]) {
    string message = (argc > 1) ? argv[1] : "Hello World !";

    // Exo 1
    cout << "Appel de printString:" << endl;
    printString(message);
    cout << endl;

    cout << "Classe my_class avec méthode printMessage:" << endl;
    my_class test(message);
    test.printMessage();
    cout << endl;

    return 0;
}