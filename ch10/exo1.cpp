#include <iostream>

// a program to implement a to_lower function

void to_lower(char* s);

int main() {
    char str1[] = "Hello, World!";

    std::cout << str1 << "\n";
    to_lower(str1);
    std::cout << str1 << "\n";

    return 0;
}

void to_lower(char* s) {
    static const char alphabet_tbl[26] = {'a', 'b', 'c', 'd', 'e',
                                'f', 'g', 'h', 'i', 'j', 'k',
                                'l', 'm', 'n', 'o', 'p', 'q',
                                'r', 's', 't', 'u', 'v', 'w',
                                'x', 'y', 'z'
                            };

    if (!s) return;

    while (*s) {
        if ('A'<=*s && *s<='Z') {
            *s = alphabet_tbl[*s - 'A'];
        }
        ++s;
    }
}
