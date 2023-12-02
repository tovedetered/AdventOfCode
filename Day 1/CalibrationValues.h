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
#include "StringUtils.h"

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
};


#endif //ADVENTOFCODE_CALIBRATIONVALUES_H
