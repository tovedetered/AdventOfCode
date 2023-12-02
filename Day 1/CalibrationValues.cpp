//
// Created by tobed on 12/1/2023.
//

#include "CalibrationValues.h"

using namespace std;

void CalibrationValues::getFile() {
    std::string line;
    ifstream fullInput("/Users/spenser/CLionProjects/AdventOfCode/Data/Data.txt", ios::in);
    if(!fullInput){
        cerr << "ERROR Data.txt could not be opened" << endl;
        exit(1);
    }
    while(getline(fullInput, line)){
        uncalibratedGibberish.push_back(line);
    }
    fullInput.close();
}

void CalibrationValues::calibrateValues() {
    string concV;
    string final;
    char first;
    char last;
    cleanValues();
    for(const string& input : cleanUncalibrated){
        for(char c : input){
            if(isdigit(c)){
                concV.push_back(c);
            }
        }
        first = *begin(concV);
        final.push_back(first);
        last = concV.back();
        final.push_back(last);

        calibratedValues.push_back(stoi(final));
        concV.clear();
        final.clear();
    }

}

int CalibrationValues::getSumOfValues() {
    int result = 0;
    for(int i : calibratedValues){
        result += i;
    }
    return result;
}

int CalibrationValues::doTheThing() {
    getFile();
    calibrateValues();
    return getSumOfValues();
}

void CalibrationValues::cleanValues() {
    string thing;
    for(const string& input : uncalibratedGibberish){
        thing = input;
        replaceAllPreserveFirstLast(thing, "one", "1");
        replaceAllPreserveFirstLast(thing, "two", "2");
        replaceAllPreserveFirstLast(thing, "three", "3");
        replaceAllPreserveFirstLast(thing, "four", "4");
        replaceAllPreserveFirstLast(thing, "five", "5");
        replaceAllPreserveFirstLast(thing, "six", "6");
        replaceAllPreserveFirstLast(thing, "seven", "7");
        replaceAllPreserveFirstLast(thing, "eight", "8");
        replaceAllPreserveFirstLast(thing, "nine", "9");
        cleanUncalibrated.push_back(thing);
    }
}