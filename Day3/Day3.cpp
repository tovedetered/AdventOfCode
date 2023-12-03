//
// Created by Spenser Kramer on 12/3/23.
//

#include <iostream>
#include "Manifold.h"

int main(){
    Manifold mani;
    mani.getFile();
    mani.findPartNumbers();
    int result = mani.getFinal();

    std::cout << result << std::endl;
    return 0;
};