//
// Created by Spenser Kramer on 12/2/23.
//

#include "PossibleGames.h"

void PossibleGames::getData() {
    std::string line;
    ifstream fullInput("/Users/spenser/CLionProjects/AdventOfCode/Day2/Data/Data.txt", ios::in);
    if(!fullInput){
        cerr << "ERROR Data.txt could not be opened" << endl;
        exit(1);
    }
    while(getline(fullInput, line)){
        lines.push_back(line);
    }
    fullInput.close();
}

void PossibleGames::determinePossibility(int red, int green, int blue) {
    greatestNums great {0, 0, 0, 0};
    for(string line : lines){
        great = findBiggestNumbers(line);
        if(great.greatRed > red || great.greatBlue > blue || great.greatGreen > green){
            possibleGameID.push_back(great.ID);
        }
        great = {0,0,0,0};
    }
}

void PossibleGames::determineLeastPossible() {
    greatestNums great {0, 0, 0, 0};
    int power;
    for(string line : lines) {
        great = findBiggestNumbers(line);
        power = great.greatGreen * great.greatBlue * great.greatRed;
        powers.push_back(power);
    }
}


numAndColor PossibleGames::getSectionDetails(const string& section, int start) {
    int pos = section.find(' ', start);
    if(pos == string::npos){
        return {0, "$$$", 0};
    }
    int pos2 = section.find(' ', pos + 1);
    int numChar = pos2 - pos;
    string temp = section.substr(pos + 1, numChar - 1);
    int tmp = stoi(temp);

    pos = pos2;
    pos2 = section.find(',', pos + 1);
    if(pos2 == string::npos){
        pos2 = section.length();
    }
    numChar = pos2 - pos;
    temp = section.substr(pos + 1, numChar - 1);
    return {tmp, temp, pos2};
}

int PossibleGames::findID(const string& input) {
    size_t pos = 0;
    size_t pos2 = 0;
    int numberOfChars = 0;
    string thing;
    pos = input.find(':', pos);
    pos2 = input.find(' ', pos2);
    numberOfChars = pos-pos2;
    thing = input.substr(pos2, numberOfChars);
    return stoi(thing);
}

long PossibleGames::findNumSemi(string input) {
    return count(input.begin(), input.end(), ';');
}

string PossibleGames::findBetweenThing(const string& input, int i) {
    size_t pos = startingPos;
    size_t pos2;
    size_t prevPos;
    size_t numChar;
    prevPos = pos;
    if(i == 0) {
        pos = input.find(':', prevPos);
    }
    else{
        pos = input.find(';', prevPos);
    }
    if(pos == string::npos){
        return "$$$";
    }
    pos2 = input.find(';', pos + 1);
    if(pos2 == string::npos){
        pos2 = input.length();
    }
    startingPos = pos2;
    numChar = pos2 - pos;
    return input.substr(pos, numChar);
}

int PossibleGames::calculateSum() {
    int total = 0;
    for(int i : powers){
        total += i;
    }
    return total;
}

greatestNums PossibleGames::findBiggestNumbers(const string& line) {
    int greatestNumRed = 0;
    int greatestNumBlue = 0;
    int greatestNumGreen = 0;
    numAndColor Selection{ 0, "$$$", 0 };
    int ID;
    long numSemi;
    string activeSelection;
    size_t prevPos;
    ID = findID(line);
    numSemi = findNumSemi(line);
    for(int i = 0; i < numSemi + 1; ++i){
        activeSelection = findBetweenThing(line, i);
        if(activeSelection == "$$$"){
            break;
        }
        while(true) {
            if(Selection.newStart == 0){
                prevPos = 0;
            }
            else{
                prevPos = Selection.newStart - 1;
            }
            Selection = getSectionDetails(activeSelection, prevPos);
            if(Selection.color == "blue"){
                if(Selection.num > greatestNumBlue) greatestNumBlue = Selection.num;
            }
            else if(Selection.color == "red"){
                if(Selection.num > greatestNumRed) greatestNumRed = Selection.num;
            }
            else if(Selection.color == "green"){
                if(Selection.num > greatestNumGreen) greatestNumGreen = Selection.num;
            }
            else if(Selection.color == "$$$"){
                break;
            }
            else{
                exit(1);
            }
        }
        Selection = {0, "$$$", 0};
    }
    startingPos = 0;
    return {greatestNumRed, greatestNumBlue,
            greatestNumGreen, ID};
}