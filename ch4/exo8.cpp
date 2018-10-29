#include <iostream>
#include <vector>
#include <map>

// a program to calculate the mode of a set of positive integers.

int main() {
	std::cout << "Enter a list of integers: " << "\n";

	std::vector<int> numbers;
	for (double temp; std::cin >> temp;) {
		numbers.push_back(temp);
	}

	if (numbers.size()) {
		std::map<int, int> freqs;

		for (auto x: numbers) {
			++freqs[x];
		}

		int largest = 0;
		int mode;

		for (const auto& it: freqs) {
			if (it.second > largest) {
				mode = it.first;
				largest = it.second;
			}
		}

		std::cout << "Mode is: " << mode << "\n";
	}

	return 0;
}
