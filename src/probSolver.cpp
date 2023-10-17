//
// Created by Nikita Nosov on 23/9/23.
//

#include "../include/probSolver.h"


int ProbSolver::factorial(int num) {
    if (num == 1) return 1;
    return num * factorial(num -1);
}

double ProbSolver::bernoulli() {
    double q = 1 - p;
    double res =(factorial(n) / (factorial(k) * factorial(n-k))) * pow(p, k) * pow(q, n-k);
    return res;
}

double ProbSolver::poisson() {
    double lmd = n * p;
    double res = ( pow(e, -lmd) * pow(lmd, k) ) / factorial(k);
    return res;
}

double ProbSolver::laplace_local() {
    double q = 1 - n;
    double npq_sqrt = sqrt(n * p * q);
    double sec = (k - n*p) / npq_sqrt;
    double fi = pow(e, -(pow(sec, 2)/2));
    double res = ( 1 / npq_sqrt) * fi;

    return res;
}

