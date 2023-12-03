//
// Created by Spenser Kramer on 12/3/23.
//

#include "Manifold.h"


Manifold::Manifold() {
    lines = nullptr;
}

void Manifold::getFile() {
    vector<char> temp;
    size_t tmp;
    greatestLineLength = 0;
    numLines = 0;
    std::string line;
    ifstream fullInput("/Users/spenser/CLionProjects/AdventOfCode/Day3/Data/Data.txt", ios::in);
    if(!fullInput){
        cerr << "ERROR Data.txt could not be opened" << endl;
        exit(1);
    }
    while(getline(fullInput, line)){
        for(char c : line){
            temp.push_back(c);
        }
        numLines ++;
        tmp = line.length();
        if(tmp > greatestLineLength) greatestLineLength = tmp;
    }
    fullInput.close();
    lines = new char[numLines * greatestLineLength];
    for(int i = 0; i < greatestLineLength * numLines; i++){
        lines[i] = temp[i];
    }
}

void Manifold::findPartNumbers() {
    partNumberDetails details{0,0,false};
    for(int currentRow = 0; currentRow < numLines; currentRow++){
        for(int column = 0; column < greatestLineLength; column++){
            if(isdigit(lines[access(column, currentRow)])) {
                details = isPartNum(column, currentRow);
                if (details.valid) {
                    partNumbers.push_back(details.partNum);
                    column += details.size;
                }
            }
        }
    }
}

size_t Manifold::access(int x, int y) const {
    return x + greatestLineLength * y;
}

partNumberDetails Manifold::isPartNum(int xLoc, int yLoc) {
    bool possible = false;
    partNumberDetails details{0,0,possible};
    int i = 0;
    while(true){
        char currentValue;
        char activeNum;
        int aXPos = xLoc + i;
        activeNum = lines[access(aXPos, yLoc)];
        if(!isdigit(activeNum)){
            possible = false;
            break;
        }
        //Look around number
        if(xLoc != 0){
            if(ispunct(lines[access(aXPos - 1, yLoc)])&& lines[access(aXPos - 1, yLoc)] != '.') possible = true;
        }
        if(xLoc < greatestLineLength){
            if(ispunct(lines[access(aXPos + 1, yLoc)]) && lines[access(aXPos + 1, yLoc)] != '.') possible = true;
        }
        if(yLoc != 0){
            if(ispunct(lines[access(aXPos, yLoc  - 1)])&& lines[access(aXPos, yLoc - 1)] != '.') possible = true;
        }
        if(yLoc < numLines){
            if(ispunct(lines[access(aXPos, yLoc + 1)])&& lines[access(aXPos, yLoc + 1)] != '.') possible = true;
        }
        if(xLoc !=0 && yLoc != 0){
            if(ispunct(lines[access(aXPos - 1, yLoc  - 1)])&& lines[access(aXPos - 1, yLoc - 1)] != '.') possible = true;
        }
        if(xLoc < greatestLineLength && yLoc < numLines){
            if(ispunct(lines[access(aXPos + 1, yLoc+ 1)])&& lines[access(aXPos + 1, yLoc + 1)] != '.') possible = true;
        }
        if(xLoc != 0 && yLoc < numLines){
            if(ispunct(lines[access(aXPos - 1, yLoc  + 1)])&& lines[access(aXPos - 1, yLoc + 1)] != '.') possible = true;
        }
        if(xLoc < greatestLineLength && yLoc != 0){
            if(ispunct(lines[access(aXPos + 1, yLoc  - 1)])&& lines[access(aXPos + 1, yLoc - 1)] != '.') possible = true;
        }
        if(possible){
            break;
        }
        i++;
    }
    if(possible){
        char activeNum;
        i = 0;
        string temp;
        int partNum;
        int sizeNum = 0;
        while(true){
            activeNum = lines[access(xLoc + i, yLoc)];
            if(isdigit(activeNum)){
                temp.push_back(activeNum);
                sizeNum ++;
                i++;
            }
            else{
                break;
            }
        }
        partNum = stoi(temp);
        temp.clear();
        details = {partNum, sizeNum, possible};
    }
    return details;
}

int Manifold::getFinal() {
    int total = 0;
    for(int i : partNumbers){
        total += i;
    }
    return total;
}
