//
// Created by Spenser Kramer on 12/3/23.
//

#ifndef ADVENTOFCODE_MANIFOLD_H
#define ADVENTOFCODE_MANIFOLD_H

#include <vector>
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

struct partNumberDetails{
    int partNum;
    int size;
    bool valid;
};

class Manifold {
public:
    Manifold();
    void getFile();
    void findPartNumbers();
    int getFinal();
private:
    char* lines;
    size_t lineLength{};
    int numLines;
    size_t greatestLineLength;
    vector<int> partNumbers;
    partNumberDetails isPartNum(int xLoc, int yLoc);
    size_t access(int x, int y) const;
};


#endif //ADVENTOFCODE_MANIFOLD_H
