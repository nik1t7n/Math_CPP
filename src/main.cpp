#include <iostream>
#include "../include/matrix.h"
#include "../include/text.h"
#include "../include/crammer.h"
#include "../include/probSolver.h"

void keyboardInterrupt(int signum) {
    std::cout << '\n';
    Text::bye();
    exit(0);
}

std::string to_lower(std::string& str) {
    for (char & i : str) {
        i = std::tolower(static_cast<unsigned char>(i));
    }
    return str;
}

int main(int argc, const char* argv[]) {
    int option;

    signal(SIGTERM, keyboardInterrupt);

    while (true)
    {

        std::cout << "\n";
        Text::matrix_menu();

        std::cin >> option;

        if (option == 1) {
            Text::matrix_sum();

        } else if (option == 2) {
            Text::matrix_diff();

        } else if (option == 3) {
            Text::matrix_prod();
        }

        else if (option == 4) {
            Text::matrix_transpose();
        }

        else if (option == 5)
        {
            Text::matrix_scale();
        }

        else if (option == 6) {
            Crammer::start_crammer();
        }

        else if (option == 7) {
            Text::matrix_det();
        }

        else if (option == 8) {
            Text::bye();
            return 0;
        }
        else if (option == 999){
            ProbSolver pbs(400, 0.2, 80);
            double res = pbs.laplace_local();
            std::cout << "res: " << res;
        }
        else {
            exit(1);
        }
    }

}

