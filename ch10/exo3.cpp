#include <iostream>
#include <cassert>

// a program to find the first occurrence of a
// C-style string in a string

const char* findx(const char* s, const char* x);
bool str_equal(const char* s1, const char* s2);

int main() {
    const char* str = findx("this is a new string", "new");
    if(str) std::cout << str << "\n";

    str = findx("this is a new string", "ab");
    if(str) std::cout << str << "\n";

    return 0;
}

const char* findx(const char* s, const char* x) {
    if (!s || !x) return nullptr;

    while (*s) {
        if (str_equal(s, x)) {
            return s;
        } 

        ++s;
    }

    return nullptr;
}

bool str_equal(const char* s1, const char* s2) {
    assert(s1 && s2);
 
    while (*s1 && *s2) {
        if (*s1++ != *s2++) return false;
    }

    if (!*s2) return true;
    else return false;
}
