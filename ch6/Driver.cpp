#include <iostream>
#include <string>
#include "Parser.hpp"
#include "TokenStreamImpl.hpp"
#include "Token.hpp"
#include "SymbolTable.hpp"

// TODO
// add support for parenthesized expressions
// add GUI

/* The calculator grammar is:
 * Calculator:
 * 		Statement
 * 		Print
 * 		Quit
 * 		Calculator Statement
 * 	Print:
 * 		;
 * 		newline
 * 	Quit:
 * 		q
 * Statement:
 * 		Declaration
 * 		Expression
 * 	Expression:
 * 		Expression + Term
 * 		Expression - Term
 * 		Term
 * 	Term:
 * 		Term * Primary
 * 		Term / Primary
 * 		Term % Primary
 * 		Primary
 * 	Primary:
 * 		Number
 * 		Name
 * 		Name = Expression
 * 	Declaration:
 * 		Let Name = Expression
 *
 *
*/

namespace {
	const std::string result = "= ";
	const std::string prompt = "> ";
}

void displayInstructions();
void calculate();

int main() {
	try {
		// predefine some names
		calculator::getSymbolTable()["pi"] = 3.1415926535;
		calculator::getSymbolTable()["e"] = 2.7182818284;

		calculate();
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
		try {
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
	 
			double exp = ps.statement();
			std::cout << "= " << exp << "\n";
		}
		catch (std::exception& e) {
			std::cerr << e.what() << "\n";
			ts->ignore(';');
		}

	}
}

void displayInstructions() {
	std::cout << "Welcome to our Calculator App!\n"
			<< "Enter expressions followed by a print character (';' or Enter).\n"
			<< "Operators currently supported are +,-,*,/.\n"
			<< "Multiple expressions can be entered on the same line\n"
			<< "by separating them by a ';'.\n";
}
