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
		double expression();

	private:
		double term();
		double primary();

	private:
		std::unique_ptr<TokenStream> ts_;
	};

}

#endif
