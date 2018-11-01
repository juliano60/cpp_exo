#include <iostream>
#include "Parser.hpp"
#include "TokenStreamImpl.hpp"
#include "Token.hpp"

// TODO
// add support for parenthesized expressions
// add support for variables
// add support for more operators
// add GUI

int main() {
	calculator::TokenStream* ts{new calculator::TokenStreamImpl};
	calculator::Parser ps;
	ps.setTokenStream(ts);

	try {
		std::cout << "> ";

		while (std::cin) {
			calculator::Token tok = ts->getNextToken();

			// skip empty lines
			switch (tok.type) {
			case calculator::TokenType::Newline:
					std::cout << "> ";
					continue;
			case calculator::TokenType::Nul:
			case calculator::TokenType::Print:
					continue;
			default:
				ts->putback(tok);
			}
	 
			double exp = ps.expression();
			std::cout << "= " << exp << "\n";
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		return 1;
	}

	return 0;
}	
