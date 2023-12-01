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
    CalibrationValues();
    void getFile(std::string filePath);
    int getSumOfValues();
private:
    std::vector<int> calibratedValues;
    void getValue(std::string inputLine);
};


#endif //ADVENTOFCODE_CALIBRATIONVALUES_H
