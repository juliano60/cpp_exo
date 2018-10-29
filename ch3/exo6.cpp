#include <iostream>
#include <string>

// a program that compute an expression given an operator
// and two operands. Operators supported are +,-,*,/,plus,
// minus,mul and div.

int main() {

	do {
		std::cout << "Enter an operator (+,-,/,*,plus,minus,mul,div) "
					"followed by two operands: \n";
	
		std::string op;
		double num1, num2;

		if (std::cin >> op >> num1 >> num2) {
			if (op == "+" || op == "plus") {
				std::cout << "Res: " << num1 + num2 << "\n";
			}
			else if (op == "-" || op == "minus") {
				std::cout << "Res: " << num1 - num2 << "\n";
			}
			else if (op == "*" || op == "mul") {
				std::cout << "Res: " << num1 * num2 << "\n";
			}
			else if (op == "/" || op == "div") {
				if (num2) {
					std::cout << "Res: " << num1 / num2 << "\n";
				}
				else {
					std::cerr << "Division by zero attempt\n";
				}
			}
			else {
				std::cerr << "Unknown operator: " << op << "\n";
			}
		}
	} while (std::cin);

	return 0;
}
