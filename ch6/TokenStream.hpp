#ifndef TOKEN_STREAM_HPP
#define TOKEN_STREAM_HPP

#include <iostream>

namespace calculator {

	struct Token;

	class TokenStream {
	public:
		virtual ~TokenStream();
		virtual void setInputStream(std::istream* in) =0;
		virtual Token getNextToken() =0;
		virtual void putback(Token) =0;
		virtual void ignore(char c) =0;
	};

}

#endif
