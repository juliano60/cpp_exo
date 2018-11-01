#ifndef TOKEN_STREAM_IMPL_HPP
#define TOKEN_STREAM_IMPL_HPP

#include "TokenStream.hpp"
#include "Token.hpp"

namespace calculator {
	// turns a stream of characters into a stream
	// of Tokens

	class TokenStreamImpl: public TokenStream {
	public:
		TokenStreamImpl();
		~TokenStreamImpl();
		void setInputStream(std::istream* in);
		Token getNextToken();
		void putback(Token);
		void ignore(char ch);

	private:
		std::istream* input_;
		bool ownsInput_;
		Token buffer_;		// hold token we put back
		bool isFull_;
	};

}

#endif
