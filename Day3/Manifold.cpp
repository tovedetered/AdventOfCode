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
    for(int i : gearRatios){
        total += i;
    }
    return total;
}

int Manifold::part1() {
    getFile();
    findPartNumbers();
    return getFinal();
}

void Manifold::findGearRatios() {
    gearDetails details {};
    for(int currentRow = 0; currentRow < numLines; currentRow++){
        for(int column = 0; column < greatestLineLength; column++){
            if(lines[access(column, currentRow)] == '*') {
                details = isGear(column, currentRow);
                if (details.valid) {
                    gearRatios.push_back(details.ratio);
                }
            }
        }
    }
}

gearDetails Manifold::isGear(int x, int y) {
    //gear is adjacent to EXACTLY 2 partNums
    gearDetails details{};
    bool possible = false;
    char currentValue;
    int numGear = 0;
    vector<int> gears;
    active character;
    int thing;
    int tX = 0;
    int startX;
    int startY;
    string number;
    //Look around gear
   for(int i = 0; i < 8; i++){
       character = circleThing(x, y, i);
       if(character.value == '$') continue;
       if(isdigit(character.value)){
           tX = character.x;
           //find left-most digit then get the number
           while(true){
               if(tX != 0){
                   if(isdigit(lines[access(tX - 1, character.y)])){
                       tX -= 1;
                   }
                   else{
                       break;
                   }
               }
               else{
                   break;
               }
           }
           if(tX != 0) startX = tX - 1;
           else startX = tX;



           while(true){
               if(!isdigit(lines[access(tX, character.y)])) break;
               number.push_back(lines[access(tX, character.y)]);
               tX += 1;
           }
           if(character.y == y + 1){
               tX = character.x - 1;
           }
           //Have coordinate of left most + 1 value and y val
           startX = clamp(tX, x + 1, x - 1);
           cerr << startX;
           if(startX == x + 1){
               if(character.y == y) i = 3;
               else if(character.y == y + 1) i = 4;
               else if(character.y == y - 1) i = 2;
               else {cerr << "Clamp failed somehow LOL"; exit(53);}
           }
           else if(startX == x - 1){
               if(character.y == y) i = 7;
               else if(character.y == y + 1) i = 6;
               else if(character.y == y - 1) i = 0;
               else {cerr << "Clamp failed somehow LOL"; exit(54);}
           }
           else if(startX == x){
               if(character.y == y + 1) i = 5; //DOWN one
               else if(character.y == y - 1) i = 1; //UP one
               else {cerr << "Clamp failed somehow LOL"; exit(55);}
           }
           else {cerr << "Clamp failed somehow LOL"; exit(56);}
           if(numGear < 2){
               gears.push_back(stoi(number));
               numGear ++;
           }
           else return {0,false};
       }
   }
   if(numGear != 2) return {0,false};

   int ratio = gears[0] * gears[1];
   details = {ratio, true};
   return details;
}

active Manifold::circleThing(int x, int y, int i) {
    switch(i){
        case 0:
            if(x != 0 && y != 0) return {x - 1, y - 1, lines[access(x - 1, y - 1)]};
            else return {0, 0, '$'};
        case 1:
            if(y != 0) return {x, y -1, lines[access(x, y - 1)]};
            else return {0, 0, '$'};
            break;
        case 2:
            if(x < greatestLineLength && y != 0) return {x + 1, y - 1, lines[access(x + 1, y - 1)]};
            else return {0, 0, '$'};
            break;
        case 3:
            if(x < greatestLineLength) return {x + 1, y, lines[access(x + 1, y)]};
            else return {0, 0, '$'};
            break;
        case 4:
            if(x < greatestLineLength && y < numLines) return {x + 1, y + 1, lines[access(x + 1, y+ 1)]};
            else return {0, 0, '$'};
            break;
        case 5:
            if(y < numLines) return {x, y + 1, lines[access(x, y + 1)]};
            else return {0, 0, '$'};
            break;
        case 6:
            if(x != 0 && y < numLines) return {x - 1, y + 1, lines[access(x - 1, y + 1)]};
            else return {0, 0, '$'};
            break;
        case 7:
            if(x != 0) return {x - 1, y + 1, lines[access(x - 1, y + 1)]};
            else return {0, 0, '$'};
            break;
        default:
            exit(3);
    }
}

int Manifold::clamp(int val, int upperBound, int lowerBound) {
    if(val <= upperBound && val >= lowerBound) return val;
    else if(val > upperBound) return upperBound;
    else return lowerBound;
}

int Manifold::part2() {
    getFile();
    findGearRatios();
    return getFinal();
}
