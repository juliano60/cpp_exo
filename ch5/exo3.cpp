#include <iostream>
#include <vector>
#include <stdexcept>
#include <numeric>
#include <limits>

// a program to calculate the sum of the first N integers
// from a series of integers.

int computeSum(const std::vector<int>& num, std::size_t n);

int main() {
	std::cout << "Enter the value of N: ";
	int n;

	if (!(std::cin >> n)) {
		return 1;
	}

	std::vector<int> numbers;

	for (int temp; std::cin >> temp;) {
		numbers.push_back(temp);
	}

	try {
		double sum = computeSum(numbers, n);

		std::cout << "Sum of the first " << n
				<< " numbers( ";

		for(int i = 0; i != n; ++i) {
			std::cout << numbers[i] << " ";
		}

		std::cout << " ) is " << sum << "\n";
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		return 1;
	}

	return 0;
}

// compute sum of first n numbers in num
// n must be in the range [0, num.size) 
//
// throws an std::invalid_argument exception if n invalid
// throws an std::runtime_error on overflow
int computeSum(const std::vector<int>& num, std::size_t n) {
	if (n >= num.size()) {
		throw std::invalid_argument("N must be in the range [0, num.size)");
	}

	double total = std::accumulate(num.begin(), num.begin()+n, 0.0);

	if (total > std::numeric_limits<int>::max()) {
		throw std::runtime_error("Overflow detected");
	}

	return static_cast<int>(total);
}
