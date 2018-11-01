#include <iostream>
#include <string>
#include "Parser.hpp"
#include "TokenStreamImpl.hpp"
#include "Token.hpp"

// TODO
// add support for parenthesized expressions
// add support for variables
// add support for more operators
// add GUI

namespace {
	const std::string result = "= ";
	const std::string prompt = "> ";
}

void displayInstructions();
void calculate();

int main() {
	try {
		calculate();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		return 1;
	}
	catch (...) {
		std::cerr << "exception\n";
		return 2;
	}

	return 0;
}	

void calculate() {
	calculator::TokenStream* ts{new calculator::TokenStreamImpl};
	calculator::Parser ps;
	ps.setTokenStream(ts);

	displayInstructions();
	std::cout << prompt;

	while (std::cin) {
			calculator::Token tok = ts->getNextToken();

			switch (tok.type) {
			case calculator::TokenType::Print:
				continue;
			case calculator::TokenType::Newline:
				std::cout << prompt;
				continue;
			case calculator::TokenType::Nul:
			case calculator::TokenType::Quit:
				return;
			default:
				ts->putback(tok);
			}
	 
			double exp = ps.expression();
			std::cout << "= " << exp << "\n";
	}
}

void displayInstructions() {
	std::cout << "Welcome to our Calculator App!\n"
			<< "Enter expressions followed by a print character (';' or Enter).\n"
			<< "Operators currently supported are +,-,*,/.\n"
			<< "Multiple expressions can be entered on the same line\n"
			<< "by separating them by a ';'.\n";
}
