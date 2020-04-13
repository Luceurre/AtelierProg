//
// Created by pglandon on 4/13/20.
//

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    for(int i = 0; i < argc; ++i) {
        cout << "Vous m'avez donné comme argument numéro " << i << " :";
        cout << argv[i] << endl;
    }

    return 0;
}