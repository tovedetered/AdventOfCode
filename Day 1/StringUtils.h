//
// Created by Spenser Kramer on 12/1/23.
//

#ifndef ADVENTOFCODE_STRINGUTILS_H
#define ADVENTOFCODE_STRINGUTILS_H


#include <string>

void replaceFirst(std::string &base, const std::string& toRep, const std::string& repWith);

void replaceAll(std::string &base, const std::string& toRep, const std::string& repWith);
void replaceAllPreserveFirstLast(std::string &base, std::string toRep, const std::string& repWith);


#endif //ADVENTOFCODE_STRINGUTILS_H
