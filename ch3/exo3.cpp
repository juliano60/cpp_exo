#include <iostream>
#include <vector>
#include <algorithm>

// a program to print three integers in order.

int main() {
	constexpr int SIZE = 3;
	std::cout << "Enter three integers: ";

	std::vector<int> numbers;
	int n;
	for (int i = 0; i != SIZE && std::cin >> n; ++i) {
		numbers.push_back(n);
	}

	if (numbers.size() != SIZE) {
		return 1;
	}

	std::sort(numbers.begin(), numbers.end());

	for (int i = 0, e = numbers.size(); i != e; ++i) {
		if (i > 0) {
			std::cout << ", ";
		}
		std::cout << numbers[i];
	}
	std::cout << "\n";

	return 0;
}
