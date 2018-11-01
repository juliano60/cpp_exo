#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

namespace calculator {

	// A Token represents a token in our numerical expression.
	// For instance in the expression 2+3, we have the three tokens
	// Token{Numeric, 2}
	// Token{Plus}
	// Token{Numeric, 3}

	enum class TokenType {
		Plus='+',
		Minus='-',
		Mult='*',
		Div='/',
		Mod='%',
		Nul='\0',
		Newline='\n',
		Print=';',
		Quit='q',
		Let='L',
		Equal='=',
		Numeric,
		Name,
	};

	struct Token {
		TokenType type;
		double nvalue;
		std::string cvalue;

		Token()=default;
		Token(TokenType);
		Token(TokenType, double);
		Token(TokenType, const std::string& cvalue);
	};

}		

#endif
