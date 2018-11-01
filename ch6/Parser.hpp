#ifndef PARSER_HPP
#define PARSER_HPP

#include "TokenStream.hpp"
#include <memory>

namespace calculator {
	class Parser {
	public:
		Parser();
		void setInputStream(std::istream* in);
		void setTokenStream(TokenStream* ts);
		double statement();

	private:
		double expression();
		double declaration();
		double term();
		double primary();

	private:
		std::unique_ptr<TokenStream> ts_;
	};

}

#endif
