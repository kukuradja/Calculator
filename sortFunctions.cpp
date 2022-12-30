#include "sortFunctions.h"
using namespace calculator;

bool calculator::ascending(const long double& a, const long double& b) {
    return a < b;
}
bool calculator::descending(const long double& a, const long double& b) {
    return a > b;
}

void calculator::selectionSort(std::vector<int>& array, std::function<bool(int, int)> comp) {
    for (int i = 0; i < array.size() - 1; i++) {
        int min_i = i;
        for (int j = i + 1; j < array.size(); j++) {
            if (comp(array[j], array[min_i]))
                min_i = j;
        }
        if (min_i != i) {
            std::swap(array[min_i], array[i]);
        }
    }
}
void calculator::doubleSelectionSort(std::vector<int>& array, std::function<bool(int, int)> comp) {
    for (int i = 0, j = array.size() - 1; i < j; i++, j--) {
        int min = array[i], max = array[i];
        int min_i = i, max_i = i;
        for (int k = i; k <= j; k++) {
            if (comp(max, array[k])) {
                max = array[k];
                max_i = k;
            }
            else if (comp(array[k], min)) {
                min = array[k];
                min_i = k;
            }
        }
        std::swap(array[i], array[min_i]);
        if (array[min_i] == max) {
            std::swap(array[j], array[min_i]);
        }
        else {
            std::swap(array[j], array[max_i]);
        }
    }
}
void calculator::bubbleSort(std::vector<int>& array, std::function<bool(int, int)> comp) {
    for (int i = 0; i < array.size() - 1; i++) {
        for (int j = 0; j < array.size() - i - 1; j++) {
            if (comp(array[j + 1], array[j])) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}
void insertionSort(std::vector<int>& array, std::function<bool(int, int)> comp) {
    for (int i = 1; i < array.size(); i++) {
        int value = array[i];
        int j = i - 1;
        while (comp(value, array[j]) && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = value;
    }
}
void shellSort(std::vector<int>& array, std::function<bool(int, int)> comp) {
    for (int value = array.size() / 2; value > 0; value /= 2) {
        for (int i = value; i < array.size(); i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= value && comp(temp, array[j - value]); j -= value) {
                array[j] = array[j - value];
            }
            array[j] = temp;
        }
    }
}
void shakerSort(std::vector<int>& array, std::function<bool(int, int)> comp) {
    bool flag = true;
    int begin = 0;
    int end = array.size() - 1;

    while (flag) {
        flag = false;
        for (int i = begin; i < end; ++i) {
            if (comp(array[i + 1], array[i])) {
                std::swap(array[i], array[i + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
        flag = false;
        --end;
        for (int i = end - 1; i >= flag; --i) {
            if (comp(array[i + 1], array[i])) {
                std::swap(array[i], array[i + 1]);
                flag = true;
            }
        }
        ++begin;
    }
}