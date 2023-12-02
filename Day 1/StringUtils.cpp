//
// Created by Spenser Kramer on 12/1/23.
//

#include "StringUtils.h"

void replaceFirst(std::string &base, const std::string& toRep,
                  const std::string& repWith) {
    size_t pos = base.find(toRep);
    if(pos == std::string::npos) return;
    base.replace(pos, toRep.length(), repWith);
}

void replaceAll(std::string &base, const std::string& toRep,
                const std::string& repWith) {
    std::string buffer;
    size_t pos = 0;
    size_t prevPos;
    while(true){
        prevPos = pos;
        pos = base.find(toRep, pos);
        if(pos == std::string::npos) break;
        buffer.append(base, prevPos, pos - prevPos);
        buffer += repWith;
        pos += toRep.size();
    }
    buffer.append(base, prevPos, base.size() - prevPos);
    base.swap(buffer);
}

void replaceAllPreserveFirstLast(std::string &base, std::string toRep,
                                 const std::string& repWith) {
    std::string buffer;
    size_t pos = 0;
    size_t prevPos;
    char startingLetter = *begin(toRep);
    char endingLetter = toRep.back();
    while(true){
        prevPos = pos;
        pos = base.find(toRep, pos);
        if(pos == std::string::npos) break;
        buffer.append(base, prevPos, pos - prevPos);
        buffer.push_back(startingLetter);
        buffer += repWith;
        buffer.push_back(endingLetter);
        pos += toRep.size();
    }
    buffer.append(base, prevPos, base.size() - prevPos);
    base.swap(buffer);
}