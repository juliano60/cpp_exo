#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <cctype>
#include <vector>

// a program that evaluates an expression given two operands and an
// operator.

namespace {
	const std::vector<std::string> digits = {
						"zero", "one", "two",
						"three","four", "five",
						"six", "seven", "eight",
						"nine",
					};
}

// convert a digit to its numerical value
// throws a std::invalid_argument on invalid input.
double get_digit(const std::string&);

int main() {
	while (std::cin) {
		try {
			std::string lhs;
			std::string rhs;
			char op;

			if (std::cin >> lhs >> rhs >> op) { 
				double num1 = get_digit(lhs);
				double num2 = get_digit(rhs);

				switch (op) {
				case '+':
					std::cout << "Res: " << num1+num2 << "\n";
					break;
				case '-':
					std::cout << "Res: " << num1-num2 << "\n";
					break;
				case '*':
					std::cout << "Res: " << num1*num2 << "\n";
					break;
				case '/':
					std::cout << "Res: " << num1/num2 << "\n";
					break;
				default:
					std::cerr << "Unknonw operator: " << op << "\n";
				}
			}
		}
		catch (std::exception& e) {
			std::cerr << e.what() << "\n";
		}
	}

	return 0;
}

double get_digit(const std::string& val) {
	auto it = std::find(digits.begin(), digits.end(), val);

	if (it != digits.end()) {
		return std::distance(digits.begin(), it);
	}
	else if (val.size() == 1 && std::isdigit(val[0])) {
		return val[0] - '0'; 
	}
	else {
		throw std::invalid_argument("Invalid digit: " + val);
	}
}
