#include <iostream>

using namespace std;

int main(int argc, char** argv){
    unsigned int option;
    string type;
    if(argc==2){
        type = argv[1];
    }
    if(type != "auto" && type !="manual"){
        cout << "Error: Usage ./main <manual/auto>\n";
        return 0;
    }
    cout << endl;
    cout << "1. Sequential" << endl;
    cout << "2. OpenMP" << endl;
    cout << "3. OpenMPI" << endl;
    cout << "4. Hybrid" << endl;
    cout << "0. Exit" << endl;
    cout << "Option: ";
    cin >> option;

    switch (option)
    {
        case 1:
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        default:
            break;
    }
}