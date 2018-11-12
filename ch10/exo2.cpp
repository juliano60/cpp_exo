#include <iostream>

// a program to copy a C-style into memory on the free store

char* strdup(const char* s);

int main() {
    char* s2 = strdup("copy this string");

    std::cout << s2 << "\n";
    delete[] s2;

    return 0;
}

char* strdup(const char* s) {
    if (!s) return nullptr;

    size_t n = 0;

    // determine source's length 
    const char* p = s;
    while (*p++) ++n;

    // +1 for the NUL character
    char* dest = new char[n+1];  

    char* d = dest; 
    while ((*d++ = *s++)) ;

    return dest;
}
