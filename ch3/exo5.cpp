#include <iostream>
#include <map>
#include <string>

// convert spelled out numbers to digits
// e.g. one => 1, two => 2

namespace {
	const std::map<std::string, int> digits = {
				std::make_pair("zero", 0),
				std::make_pair("one", 1),
				std::make_pair("two", 2),
				std::make_pair("three", 3),
				std::make_pair("four", 4),
				std::make_pair("five", 5),
				std::make_pair("six", 6),
				std::make_pair("seven", 7),
				std::make_pair("eight", 8),
				std::make_pair("nine", 9),
			};
}

int main() {
	std::string word;
	std::cout << "Enter spelled out digit: ";

	while (std::cin >> word) {
		auto it = digits.find(word);

		if (it != digits.end()) {
			std::cout << "Digit: " << it->second << "\n";
		}
		else {
			std::cout << word << " is not a digit\n";
		}

		std::cout << "Enter spelled out digit: ";
	}

	return 0;
}
