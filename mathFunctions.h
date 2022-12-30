#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H
namespace calculator {

#define EPSILON 0.000'000'001

    template<typename T>
    T absolute(const T number) {
        return (number >= 0) ? number : -number;
    }

    template <typename T>
    double reciprocal(const T number) {
        return 1.0 / number;
    }

    template<typename T>
    double power(const T number, const int pow) {
        double res = 1;
        if (pow >= 0) {
            for (int i = 0; i < pow; i++) {
                res *= number;
            }
        }
        else {
            double reciprocal_number = reciprocal(number);
            for (int i = 0; i < absolute(pow); i++) {
                res *= reciprocal_number;
            }
        }
        return res;
    }

    long long factorial(const long long);

    template <typename T>
    double radical(const T number, const int pow) {
        if (pow % 2 == 0 && number < 0) {
            throw "Less then zero!\n";
        }
        if (pow <= 0) {
            throw "Such radical doesnt exist!\n";
        }
        else {
            int multer = 1;
            for (; calculator::power(multer, pow) < number; multer++) {}
            double number_ = static_cast<double>(number) / calculator::power(multer, pow) - 1;
            if (number_ == 0.0) {
                return multer;
            }
            int denom = 1;
            double res = 1;
            double pseudo_mu = 1.0 / pow;
            double mu = pseudo_mu;

            for (int i = 1; i < 20; i++)
            {
                res += (mu * number_) / calculator::factorial(denom);
                denom++;
                pseudo_mu -= 1;
                mu *= pseudo_mu;
                number_ *= number_;
            }
            res *= multer;
            return res;
        }
    }

    template <typename T>
    double percentage(T part, T all) {
        return static_cast<double>(part) / all;
    }

    template <typename T>
    double cosinus(T arg) {
        double temp = arg;
        while (absolute(temp) >= 180)
            temp = absolute(temp) - 180;           // но есть проблема со знаком после (-180,180)
        double rad = temp * 3.1415926 / 180;
        double res = 0;
        for (int i = 0; i <= 20; i++) {
            res += (power(-1, i) * power(rad, 2 * i)) / factorial(2 * i);
        }
        return res;
    }
        
    template <typename T>
    double sinus(T arg) {
        double temp = arg;
        while (absolute(temp) >= 180) {
            temp = absolute(temp) - 180;
        }
        double rad = temp * 3.1415926 / 180;
        double res = 0;
        for (int i = 0; i <= 20; i++) {            // но есть проблема со знаком после (-180,180)
            res += (power(-1, i) * power(rad, 2 * i + 1)) / factorial(2 * i + 1);
        }

        return res;
    }

    template <typename T>
    double tangens(T arg) {
        return sinus(arg) / cosinus(arg);
    }

    template <typename T>
    double cotangens(T arg) {
        return cosinus(arg) / sinus(arg);
    }
}
#endif MATHFUNCTIONS_H