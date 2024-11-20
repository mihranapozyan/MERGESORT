# MergeSort Implementation

This repository contains an implementation of the MergeSort algorithm in C++ using templates. The MergeSort algorithm is a divide-and-conquer sorting algorithm that efficiently sorts arrays or vectors in O(n log n) time.

## Features

- **Generic Template Class**: The `MergeSort` class works with any type that supports the `<` operator for comparison.
- **Efficient Sorting**: MergeSort guarantees an O(n log n) time complexity in the worst case, making it suitable for sorting large datasets.

## How to Use

1. Include the `MergeSort.h` header file in your project.
2. Instantiate the `MergeSort` template class for the type you want to sort (e.g., `MergeSort<int>`, `MergeSort<std::string>`).
3. Call the static `sort()` method to sort a vector.

### Example Usage

```c++
#include <iostream>
#include <vector>
#include "MergeSort.h"

int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    MergeSort<int>::sort(arr);

    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
