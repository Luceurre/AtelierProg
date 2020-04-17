//
// Created by pglandon on 4/13/20.
//

#include <iostream>
#include "API/Logger.h"

using namespace std;

int main(int argc, char* argv[]) {
    for(int i = 0; i < argc; ++i) {
        cout << "Vous m'avez donné comme argument numéro " << i << " : ";
        cout << argv[i] << endl;
    }

    Logger::warn("Le programme se termine.");

    return 0;
}