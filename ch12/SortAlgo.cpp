#include "SortAlgo.hpp"
#include <iostream>
#include <utility>

void sort(int* beg, int* end) {
    for (int* p = beg; p != end; ++p) {
        int curr = *p;
        int* q = p - 1;
        while (q >= beg && *q > curr) {
            *(q+1) = *q;
            --q;
        }
        *(q+1) = curr;
    }
}
