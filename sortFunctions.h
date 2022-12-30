#ifndef SORTFUNCTIONS_H
#define SORTFUNCTIONS_H
#include <vector>
#include <functional>
namespace calculator {


    inline bool ascending(const long double& a, const long double& b);
    inline bool descending(const long double& a, const long double& b);
    void selectionSort(std::vector<int>& array, std::function<bool(int, int)> comp = ascending);
    void doubleSelectionSort(std::vector<int>& array, std::function<bool(int, int)> comp = ascending);
    void bubbleSort(std::vector<int>& array, std::function<bool(int, int)> comp = ascending);
    void insertionSort(std::vector<int>& array, std::function<bool(int, int)> comp = ascending);
    void shellSort(std::vector<int>& array, std::function<bool(int, int)> comp);
    void shakerSort(std::vector<int>& array, std::function<bool(int, int)> comp = ascending);
}
#endif SORTFUNCTIONS_H