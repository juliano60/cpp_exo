#include "Token.hpp"

namespace calculator {

	Token::Token(TokenType t):
		type{t}
	{}

	Token::Token(TokenType t, double value):
		type{t},
		nvalue{value}
	{}

	Token::Token(TokenType t, const std::string& value):
		type{t},
		cvalue{value}
	{}

}

