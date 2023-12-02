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
    int ID;
    long numSemi;
    string thing;
    string temp;
    size_t prevPos;
    size_t pos = 0;
    size_t pos2 = 0;
    size_t numChar;
    int greatestNumRed = 0;
    int greatestNumBlue = 0;
    int greatestNumGreen = 0;
    int tmp = 0;
    bool possible;
    for(string line : lines){
        //Split into each pull
        //Read Id -> up to colon
        ID = findID(line);
        //Read pull to semicolon or End line
        numSemi = findNumSemi(line);
        for(int i = 0; i < numSemi + 1; ++i){
            thing = findBetweenThing(line, i);
            if(thing == "$$$"){
                break;
            }
            //read the line
            while(true) {
                if(pos2 == 0){
                    prevPos = pos2;
                }
                else{
                    prevPos = pos2 - 1;
                }

                pos = thing.find(' ', prevPos);
                if(pos == string::npos){
                    break;
                }
                pos2 = thing.find(' ', pos + 1);
                numChar = pos2 - pos;
                temp = thing.substr(pos + 1, numChar - 1);
                tmp = stoi(temp);

                pos = pos2;
                pos2 = thing.find(',', pos + 1);
                if(pos2 == string::npos){
                    pos2 = thing.length();
                }
                numChar = pos2 - pos;
                temp = thing.substr(pos + 1, numChar - 1);
                if(temp == "blue"){
                    if(tmp > greatestNumBlue) greatestNumBlue = tmp;
                }
                else if(temp == "red"){
                    if(tmp > greatestNumRed) greatestNumRed = tmp;
                }
                else if(temp == "green"){
                    if(tmp > greatestNumGreen) greatestNumGreen = tmp;
                }
                else{
                    exit(1);
                }
            }
            pos2 = 0;
            // 3 blue, 4 red
        }
        startingPos = 0;
        //Know number of each type in pull

        //determine if possible
        if(greatestNumRed > red || greatestNumBlue > blue || greatestNumGreen > green){
            possible = false;
        }
        else{
            possible = true;
        }
        if(possible) {
            possibleGameID.push_back(ID);
        }
        possible = false;
        greatestNumRed = 0;
        greatestNumGreen = 0;
        greatestNumBlue = 0;

    }

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
    for(int i : possibleGameID){
        total += i;
    }
    return total;
}
