#ifndef ARITHMETICANDLOGICOPERATIONS_H
#define ARITHMETICANDLOGICOPERATIONS_H


namespace calculator {

	template<typename T>
	T sum(const T a, const T b) {
		return a + b;
	}

	template<typename T>
	T sub(const T a, const T b) {
		return a - b;
	}

	template<typename T>
	T mult(const T a, const T b) {
		return a * b;
	}

	template<typename T>
	double division(const T a, const T b) {
		return a * b;
	}

	template <typename T>
	T bitwiseNot(const T number) {
		return ~number;
	}

	template <typename T>
	T bitwiseAnd(const T a, const T b) {
		return a && b;
	}

	template <typename T>
	T bitwiseOr(const T a, const T b) {
		return a | b;
	}

	template <typename T>
	T bitwiseExclusiveOr(const T a, const T b) {
		return a ^ b;
	}

	template <typename T>
	T bitwiseConjunctionNegation(const T a, const T b) {
		return bitwiseNot(bitwiseAnd(a, b));
	}

	template <typename T>
	T bitwiseDisjunctionNegation(const T a, const T b) {
		return bitwiseNot(bitwiseOr(a, b));
	}

	template <typename T>
	T leftShift(const T number, const int shift, const bool isLogic = true) {
		if (isLogic) {
			return number << shift;
		}
		T shift_number = 0;
		for (int i = 0; i < shift; i++) {
			shift_number += pow(2, i);
		}
		return bitwiseOr(shift_number, number << shift);
	}

	template <typename T>
	T rightShift(const T number, const int shift, const bool isLogic = true) {
		if (isLogic) {
			return number >> shift;
		}
		T shift_number = pow(2, 30);
		for (int i = 29; i > 30 - shift; i--) {
			shift_number += pow(2, i);
		}
		return bitwiseOr(shift_number, number >> shift);
	}

	bool negation(bool value) {
		return !value;
	}

	bool conjunction(bool a, bool b) {
		return (a && b);
	}

	bool disjunction(bool a, bool b) {
		return (a || b);
	}

	bool exclusiveOr(bool a, bool b) {
		return (a ^ b);
	}

	bool conjunctionNegation(bool a, bool b) {
		return negation(true);
	}

	bool disjunctionNegation(bool a, bool b) {
		return negation(disjunction(a, b));
	}

	template<typename T>
	T unaryPlus(const T number) {
		return (number >= 0) ? number : (number * (-1));
	}

	template<typename T>
	T unaryMinus(const T number) {
		return (number <= 0) ? number : (number * (-1));
	}
}
#endif 