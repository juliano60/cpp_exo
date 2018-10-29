#include <iostream>

// a program to determine whether a number is odd or even.
bool isEven(int x);

int main() {
	std::cout << "Enter number: ";
	int num;

	if (std::cin >> num) {
		if (isEven(num)) {
			std::cout << num << " is even\n";
		}
		else {
			std::cout << num << " is odd\n";
		}
	}

	return 0;
}

bool isEven(int x) {
	return (x % 2) == 0;
}
