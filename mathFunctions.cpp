#include "mathFunctions.h"
using namespace calculator;

long long calculator::factorial(const long long number) {
	if (number < 0) {
		throw "Error";
	}
	else {
		return (number <= 1) ? 1 : number * calculator::factorial(number - 1);
	}
}