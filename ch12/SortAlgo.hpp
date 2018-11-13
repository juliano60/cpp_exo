#ifndef SORT_ALGO_HPP
#define SORT_ALGO_HPP

#include <iostream>

// implementation of the insertion sort algorithm
// Sort a sequence of elements delimited by a pair
// of begin and end iterators.

void sort(int* beg, int* end);

template <typename T, size_t N>
void print_arr(const T (&arr)[N]) {
    for (auto i = 0; i != N; ++i) {
       std::cout << arr[i];
       if (i < N-1) std::cout << " ";
    }
    std::cout << "\n";
}

#endif

