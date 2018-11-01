#include "Parser.hpp"
#include "Token.hpp"
#include "TokenStreamImpl.hpp"
#include <stdexcept>

namespace calculator {

		Parser::Parser()
			: ts_{new TokenStreamImpl}
		{}

		void Parser::setInputStream(std::istream* in) {
			ts_->setInputStream(in);
		}

		void Parser::setTokenStream(TokenStream* ts) {
			ts_.reset(ts);
		}

		double Parser::expression() {
			double lhs = term(); 

			while (true) {
				Token token = ts_->getNextToken();

				switch (token.type) {
				case TokenType::Plus: 
					lhs += term();
					break;
				case TokenType::Minus:
					lhs -= term();
					break;
				default:
					return lhs;
				}
			}
			return 0;
		}

		double Parser::term() {
			double lhs = primary(); 

			while (true) {
				Token token = ts_->getNextToken();

				switch (token.type) {
				case TokenType::Mult:
					lhs *= primary();
					break;
				case TokenType::Div:
				{
					if (double rhs = primary()) {
						lhs /= rhs;
					}
					else {
						throw std::runtime_error("Division by 0");
					}
					break;
				}
				default:
					ts_->putback(token);
					return lhs;
				}
			} 
			return 0;
		}

		double Parser::primary() {
			Token token = ts_->getNextToken();

			switch (token.type) {
			case TokenType::Numeric:
					return token.nvalue;
			default:
					throw std::runtime_error("Primary expected");
			}
		}

}
