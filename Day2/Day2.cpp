//
// Created by Spenser Kramer on 12/2/23.
//
#include <iostream>
#include "PossibleGames.h"

using namespace std;

int main(){
    PossibleGames possible;
    possible.getData();
    possible.determineLeastPossible();
    int result = possible.calculateSum();
    cout << result << endl;
    return 0;
}