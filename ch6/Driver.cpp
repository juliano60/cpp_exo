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
		while (std::cin) {
			std::cout << "Expression: ";
			
			calculator::Token tok = ts->getNextToken();

			// skip empty lines
			switch (tok.type) {
			case calculator::TokenType::Newline:
			case calculator::TokenType::Nul:
					continue;
			default:
				ts->putback(tok);
			}
	 
			double exp = ps.expression();
			std::cout << "Result: " << exp << "\n";
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		return 1;
	}

	return 0;
}	
