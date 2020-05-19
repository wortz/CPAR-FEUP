#include <iostream>
#include <string>

#include "Sequential.h"
#include "OpenMP.h"

#include "Utils.h"

using namespace std;

int main(int argc, char** argv){
    unsigned int option;
    string type;
    if(argc==2){
        type = argv[1];
    }
    if(type != "auto" && type !="manual" && !isdigit(atoi(argv[1]))){
        cout << "Error: Usage ./main <manual/auto/exponent>\n";
        return 0;
    }
    cout << endl;
    cout << "1. Sequential" << endl;
    cout << "2. OpenMP" << endl;
    cout << "Option: ";
    cin >> option;

    switch (option)
    {
        case 1:
            if (type == "auto"){
                autoSequential();
            }else if (type == "manual"){
                manualSequential();
            }
            break;

        case 2:
            if (type == "auto"){
                autoOpenMP();
            }else if (type == "manual"){
                manualOpenMP();
            }
            break;

        default:
            break;
    }

    return 0;
}