#include "MergeSort.h"
#include <vector>
#include <string>

// The mergeSort function is a helper function that divides the vector into two halves
// and recursively sorts them.
template<typename T>
void MergeSort<T>::mergeSort(std::vector<T>& av_vec, const std::size_t ai_left, const std::size_t ai_right) {
    // Base case: if the left index is greater than or equal to the right index,
    // the array (or sub-array) is already sorted (1 element or empty).
    if (ai_right > ai_left) {
        // Find the middle point of the current array range.
        // It's calculated as the left index plus half of the size of the current range.
        const std::size_t li_mid = ai_left + (ai_right - ai_left) / 2;

        // Recursively call mergeSort to sort the left half of the array
        mergeSort(av_vec, ai_left, li_mid);

        // Recursively call mergeSort to sort the right half of the array
        mergeSort(av_vec, li_mid + 1, ai_right);

        // Merge the two sorted halves back together into the original array
        merge(av_vec, ai_left, li_mid, ai_right);
    }
}

// The merge function combines two sorted sub-arrays into one sorted array.
// This is the key step that combines the result of the recursive calls.
template<typename T>
void MergeSort<T>::merge(std::vector<T>& av_vec, const std::size_t ai_left, const std::size_t ai_mid, const std::size_t ai_right) {
    // Calculate the lengths of the left and right sub-arrays.
    std::size_t li_leftLen = ai_mid - ai_left + 1;
    std::size_t li_rightLen = ai_right - ai_mid;

    // Create temporary arrays to hold the left and right sub-arrays.
    std::vector<T> lv_leftVec(li_leftLen);
    std::vector<T> lv_rightVec(li_rightLen);

    // Copy the data from the original array into the temporary left and right sub-arrays.
    for (std::size_t i = 0; i < li_leftLen; i++) {
        lv_leftVec[i] = av_vec[ai_left + i]; // Copy the left part of the array.
    }

    for (std::size_t i = 0; i < li_rightLen; i++) {
        lv_rightVec[i] = av_vec[ai_mid + 1 + i]; // Copy the right part of the array.
    }

    // Indices to traverse the left, right, and original arrays during the merge process.
    std::size_t i = 0, j = 0, k = ai_left;

    // Compare elements from the left and right sub-arrays and place the smaller one in the original array.
    while (i < li_leftLen && j < li_rightLen) {
        if (lv_leftVec[i] < lv_rightVec[j]) {
            av_vec[k++] = lv_leftVec[i++]; // Take from the left sub-array
        } else {
            av_vec[k++] = lv_rightVec[j++]; // Take from the right sub-array
        }
    }

    // If there are any remaining elements in the left sub-array, add them to the original array.
    while (i < li_leftLen) {
        av_vec[k++] = lv_leftVec[i++]; // Copy the remaining elements from the left sub-array
    }

    // If there are any remaining elements in the right sub-array, add them to the original array.
    while (j < li_rightLen) {
        av_vec[k++] = lv_rightVec[j++]; // Copy the remaining elements from the right sub-array
    }
}

// This is the main public function that can be called to sort the vector.
// It checks if the vector is already sorted (or has only one element) and calls mergeSort to sort it.
template<typename T>
void MergeSort<T>::sort(std::vector<T>& av_vec) {
    // If the vector has 1 or fewer elements, it's already sorted.
    if (av_vec.size() <= 1) {
        return;
    }
    // Call the recursive mergeSort function to sort the entire array
    mergeSort(av_vec, 0, av_vec.size() - 1);
}

// Explicit template instantiation for common types (to avoid linker errors).
// These lines ensure that the MergeSort class is instantiated for specific types.
template class MergeSort<int>;
template class MergeSort<double>;
template class MergeSort<float>;
template class MergeSort<std::string>;
template class MergeSort<char>;
