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
};


#endif //ADVENTOFCODE_POSSIBLEGAMES_H
