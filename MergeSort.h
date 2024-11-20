#ifndef MERGESORT_H
#define MERGESORT_H
#include <vector>

// Template class definition for MergeSort
template <typename T>
class MergeSort {
    // Private static helper function for recursively splitting the vector into smaller parts
    static void mergeSort(std::vector<T>& av_vec, std::size_t ai_left, std::size_t ai_right);

    // Private static helper function to merge two sorted subarrays back together
    static void merge(std::vector<T>& av_vec, std::size_t ai_left, std::size_t ai_mid, std::size_t ai_right);

public:
    // Public static function to initiate the sorting of the vector
    static void sort(std::vector<T>& av_vec);
};

#endif //MERGESORT_H
