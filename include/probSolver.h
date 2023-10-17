//
// Created by Nikita Nosov on 23/9/23.
//

#ifndef MATH_PROBSOLVER_H
#define MATH_PROBSOLVER_H

#include <iostream>
#include <sstream>
#include "crammer.h"
#include <map>

class ProbSolver {
public:
    ProbSolver(double amount, double prob, double target) {
        this->p = prob;
        this->n = amount;
        this->k = target;
    }

    double bernoulli();
    double poisson();
    double laplace_local();
private:
    double p, n, k;
    int factorial(int num);
    std::map<double, double> table();
    double pi = 3.14159265358979323846;
    double e = 2.7182818284590452353602874713527;
};


#endif //MATH_PROBSOLVER_H
