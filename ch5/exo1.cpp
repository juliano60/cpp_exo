#include <iostream>

// a program to compute the sum of two integers

int computeSum(int a, int b) {
	return a+b;
}

int main() {
	int num1;
	int num2;

	if (std::cin >> num1 >> num2) {
		std::cout << computeSum(num1, num2) << "\n";
	}

	return 0;
}
