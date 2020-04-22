//
// Created by pglandon on 4/22/20.
//

#include "tools.h"

std::vector<std::string> split(const std::string& text, char split_identifier) {
    std::vector<std::string> split_text;
    std::string curr;
    for(auto chara : text) {
        if(chara == split_identifier) {
            split_text.push_back(curr);
            curr = "";
        } else {
            curr += chara;
        }
    }

    split_text.push_back(curr);

    return split_text;
}