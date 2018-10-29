#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

// a program to convert digits to spelled out digits

namespace {
	const std::vector<std::string> digits = {
						"zero", "one", "two",
						"three","four", "five",
						"six", "seven", "eight",
						"nine",
					};
}

int main() {
	while (std::cin) {
		std::cout << "Enter a digit: ";

		std::string input;
		if (std::cin >> input) {
			auto it = std::find(digits.begin(), digits.end(), input);

			if (it != digits.end()) {
				std::cout << "Digit: " << std::distance(digits.begin(), it) << "\n";
			}
			else if (input.size() == 1 && std::isdigit(input[0])) {
				std::cout << "Digit: " << digits[input[0] - '0'] << "\n";
			}
			else {
				std::cerr << "Invalid digit: " << input << "\n";
			}
		}
	}

	return 0;
}
