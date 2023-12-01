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
    for(string input : uncalibratedGibberish){
        replaceAllPreserveFirstLast(input, "one", "1");
        replaceAllPreserveFirstLast(input, "two", "2");
        replaceAllPreserveFirstLast(input, "three", "3");
        replaceAllPreserveFirstLast(input, "four", "4");
        replaceAllPreserveFirstLast(input, "five", "5");
        replaceAllPreserveFirstLast(input, "six", "6");
        replaceAllPreserveFirstLast(input, "seven", "7");
        replaceAllPreserveFirstLast(input, "eight", "8");
        replaceAllPreserveFirstLast(input, "nine", "9");
        cleanUncalibrated.push_back(input);
    }
}

void CalibrationValues::replaceFirst(string &base, const std::string& toRep,
                                     const std::string& repWith) {
    size_t pos = base.find(toRep);
    if(pos == string::npos) return;
    base.replace(pos, toRep.length(), repWith);
}

void CalibrationValues::replaceAll(string &base, const std::string& toRep,
                                   const std::string& repWith) {
    string buffer;
    size_t pos = 0;
    size_t prevPos;
    while(true){
        prevPos = pos;
        pos = base.find(toRep, pos);
        if(pos == string::npos) break;
        buffer.append(base, prevPos, pos - prevPos);
        buffer += repWith;
        pos += toRep.size();
    }
    buffer.append(base, prevPos, base.size() - prevPos);
    base.swap(buffer);
}

void CalibrationValues::replaceAllPreserveFirstLast(string &base,
                                                    std::string toRep,
                                                    const std::string& repWith) {
    string buffer;
    size_t pos = 0;
    size_t prevPos;
    char startingLetter = *begin(toRep);
    char endingLetter = toRep.back();
    while(true){
        prevPos = pos;
        pos = base.find(toRep, pos);
        if(pos == string::npos) break;
        buffer.append(base, prevPos, pos - prevPos);
        buffer += repWith;
        buffer.push_back(startingLetter);
        buffer.push_back(endingLetter);
        pos += toRep.size();
    }
    buffer.append(base, prevPos, base.size() - prevPos);
    base.swap(buffer);
}
