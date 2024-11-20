#include <iostream>
#include <vector>
#include "MergeSort.h"

int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    std::cout << "Original array: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    MergeSort<int>::sort(arr);

    std::cout << "Sorted array:   ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> strArr = {"apple", "orange", "banana", "kiwi", "grape"};

    std::cout << "Original string array: ";
    for (const auto& str : strArr) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    MergeSort<std::string>::sort(strArr);

    std::cout << "Sorted string array: ";
    for (const auto& str : strArr) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
