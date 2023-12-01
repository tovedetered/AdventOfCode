//
// Created by tobed on 12/1/2023.
//

#ifndef ADVENTOFCODE_CALIBRATIONVALUES_H
#define ADVENTOFCODE_CALIBRATIONVALUES_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

class CalibrationValues {
public:
    CalibrationValues() = default;
    int doTheThing();
    int getSumOfValues();
    void calibrateValues();
    void getFile();
private:
    std::vector<std::string> uncalibratedGibberish;
    std::vector<std::string> cleanUncalibrated;
    std::vector<int> calibratedValues;
    void cleanValues();
    static void replaceFirst(std::string &base, const std::string& toRep, const std::string& repWith);
    static void replaceAll(std::string &base, const std::string& toRep, const std::string& repWith);
    void replaceAllPreserveFirstLast(std::string &base, std::string toRep,const std::string& repWith);
};


#endif //ADVENTOFCODE_CALIBRATIONVALUES_H
