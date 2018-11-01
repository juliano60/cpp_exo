#include "catch.hpp"
#include "Parser.hpp"
#include "Token.hpp"
#include "TokenStream.hpp"
#include <array>

using namespace calculator;

// TODO: we could initialise MockTokenStream with an array
// of tokens to make it more useful or perhaps create tokens
// from a string.

namespace {
	class MockTokenStream: public TokenStream {
	public:
		void setInputStream(std::istream*) {}
		void ignore(char) {}
		Token getNextToken() {
			static std::array<Token, 6> tokens = {
					Token{TokenType::Numeric, 2},
					Token{TokenType::Plus},
					Token{TokenType::Numeric, 3.1},
					Token{TokenType::Mult},
					Token{TokenType::Numeric, 4},
					Token{TokenType::Nul},
			};

			++index_;
			assert(index_ < static_cast<int>(tokens.size()));

			return tokens[index_];
		}

		void putback(Token) {
			--index_;
		}

	private:
		int index_ = -1;
	};
}

TEST_CASE ("evaluateSimpleExpression") {
	Parser ps;
	ps.setTokenStream(new MockTokenStream);
	
	REQUIRE (ps.statement() == Approx(14.4));
}
