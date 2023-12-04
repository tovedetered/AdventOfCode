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
struct gearDetails{
    int ratio;
    bool valid;
};
struct active{
    int x;
    int y;
    char value;
};

class Manifold {
public:
    Manifold();
    void getFile();
    void findPartNumbers();
    void findGearRatios();
    int getFinal();
    int part1();
    int part2();
private:
    char* lines;
    size_t lineLength{};
    int numLines;
    size_t greatestLineLength;
    vector<int> partNumbers;
    vector<int> gearRatios;
    partNumberDetails isPartNum(int xLoc, int yLoc);
    gearDetails isGear(int x, int y);
    size_t access(int x, int y) const;
    active circleThing(int x, int y, int i);
    static int clamp(int val, int upperBound, int lowerBound);
};


#endif //ADVENTOFCODE_MANIFOLD_H
