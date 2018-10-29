#include <iostream>

// a program that evaluates an expression given two operands and an
// operator.

int main() {
	while (std::cin) {
		double num1, num2;
		char op;

		if (std::cin >> num1 >> num2 >> op) {
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

	return 0;
}

