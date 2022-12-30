#include  <iostream>
#include "mathFunctions.h"
#include "arithmeticAndLogicOperators.h"
#include <string>

using namespace::calculator;
int main() {
    std::cout << sum(34, 30) << "\n";
    std::cout << bitwiseAnd(44, 3) << "\n";
    std::cout << leftShift(1, 2, false) << "\n";
    std::cout << reciprocal(5) << '\n';
    std::cout << sinus(-60) << '\n';
    std::cout << cosinus(-60) << '\n';
    std::cout << cotangens(45) << '\n';
    std::cout << tangens(45) << '\n';
    std::cout << radical(9, 2) << '\n';
    return 0;
}