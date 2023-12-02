//
// Created by Spenser Kramer on 12/2/23.
//

#ifndef ADVENTOFCODE_POSSIBLEGAMES_H
#define ADVENTOFCODE_POSSIBLEGAMES_H

#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>

struct numAndColor{
    int num;
    std::string color;
    int newStart;
};

struct greatestNums{
    int greatRed;
    int greatBlue;
    int greatGreen;
    int ID;
};

using namespace std;

class PossibleGames {
public:
    PossibleGames(){
        startingPos = 0;
    };
    int doTheThing();
    int calculateSum();
    void getData();
    void determinePossibility(int red, int green, int blue);
private:
    vector<int> possibleGameID;
    vector<string> lines;
    vector<string> temp;
    size_t startingPos;
    static int findID(const string& input);
    static long findNumSemi(string input);
    string findBetweenThing(const string& input, int i);
    greatestNums findBiggestNumbers(const string& line);
    static numAndColor getSectionDetails(const string& section, int start);
};


#endif //ADVENTOFCODE_POSSIBLEGAMES_H
