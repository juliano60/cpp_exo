#include <iostream>

// a program to display the min, max, sum,
// difference, product of two integers.

int main() {
	std::cout << "Enter two integers: ";
	int num1, num2;

	if (std::cin >> num1 >> num2) {
		std::cout << "Minimum: " << std::min(num1, num2) << "\n";
		std::cout << "Maximum: " << std::max(num1, num2) << "\n";
		std::cout << "Sum: " << num1+num2 << "\n";
		std::cout << "Difference: " << num1-num2 << "\n";
		std::cout << "Product: " << num1*num2 << "\n";
	}

	return 0;
}


