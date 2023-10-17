//
// Created by Nikita Nosov on 21/9/23.
//

#ifndef MATH_CRAMMER_H
#define MATH_CRAMMER_H

#include <iostream>

const std::string RED_COLOR = "\x1B[31m";
const std::string GREEN_COLOR = "\x1B[32m";
const std::string PURPLE_COLOR = "\x1B[35m";
const std::string RESET_COLOR = "\x1B[0m";

class Crammer {
public:
    static std::vector<float> get_ratio(const std::string& equation);
    static bool is_correct(const std::string& equation);
    static void start_crammer();
};


#endif //MATH_CRAMMER_H
