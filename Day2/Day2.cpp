//
// Created by Spenser Kramer on 12/2/23.
//
#include <iostream>
#include "PossibleGames.h"

using namespace std;

int main(){
    PossibleGames possible;
    possible.getData();
    possible.determinePossibility(12,13,14);
    int result = possible.calculateSum();
    cout << result << endl;
    return 0;
}