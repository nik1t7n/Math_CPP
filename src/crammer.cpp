//
// Created by Nikita Nosov on 21/9/23.
//

#include "../include/crammer.h"


std::vector<float> Crammer::get_ratio(const std::string &equation) {
    std::vector<float> ratios;

    std::string currNumber;
    float currentCoefficient = 1.0f;

    for (char sym : equation) {
        if (std::isdigit(sym) || sym == '-' || sym == '.' || sym == '+') {
            currNumber += sym;
        } else if (sym == 'x' || sym == 'y') {
            if (!currNumber.empty()) {
                if (currNumber == "+") {
                    currentCoefficient = 1.0f;
                } else if (currNumber == "-") {
                    currentCoefficient = -1.0f;
                } else {
                    try {
                        currentCoefficient = std::stof(currNumber);
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Error: Invalid coefficient: " << currNumber << std::endl;
                        exit(1);
                    }
                }
                currNumber.clear();
            }
            ratios.push_back(currentCoefficient);
            currentCoefficient = 1.0f;
        }
    }

    if (!currNumber.empty()) {
        try {
            currentCoefficient = std::stof(currNumber);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid coefficient: " << currNumber << std::endl;
            exit(1);
        }
    }

    ratios.push_back(currentCoefficient);

    return ratios;
}

bool Crammer::is_correct(const std::string &equation) {
    bool found_x = false;
    for (char sym : equation) {
        if (sym == 'x')
            found_x = true;
        else if (sym == 'y' && !found_x)
            return false;
    }
    return found_x;
}

void Crammer::start_crammer() {
    std::cout << RED_COLOR <<"\n[STRUCTURE: ax + by = c]\n\n" << RESET_COLOR;

    std::string equation1;
    std::cout << "Insert first equation: ";
    std::cin.ignore(); // Очистка буфера ввода
    std::getline(std::cin, equation1);

    if (!Crammer::is_correct(equation1)) {
        std::cerr << "Error: wrong equation" << std::endl;
        exit(1);
    }

    std::string equation2;
    std::cout << "Insert second equation: ";
    std::getline(std::cin, equation2);

    if (!Crammer::is_correct(equation2)) {
        std::cerr << "Error: wrong equation" << std::endl;
        exit(1);
    }

    std::vector<float> r1 = Crammer::get_ratio(equation1);
    std::vector<float> r2 = Crammer::get_ratio(equation2);

    float det = r1[0] * r2[1] - r2[0] * r1[1];
    float x_det = r1[2] * r2[1] - r2[2] * r1[1];
    float y_det = r1[0] * r2[2] - r2[0] * r1[2];

    float x_answer = x_det / det;
    float y_answer = y_det / det;

    std::cout << "\n";

    std::cout << "General Determinant: " << det << "\nX-Determinant: " << x_det << "\nY-Determinant: " << y_det << "\n";

    std::cout << RED_COLOR << "\n[ANSWERS]\n" << RESET_COLOR;

    std::cout << GREEN_COLOR <<"X" << RESET_COLOR <<" = " << x_answer << GREEN_COLOR <<"Y" << RESET_COLOR << " = " << y_answer << "\n\n";
}
