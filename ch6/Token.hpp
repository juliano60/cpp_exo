#ifndef TOKEN_HPP
#define TOKEN_HPP

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
		Nul='\0',
		Newline='\n',
		Numeric,
	};

	struct Token {
		TokenType type;
		double nvalue;
	};

}		

#endif
