#include "Parser.hpp"
#include "Token.hpp"
#include "TokenStreamImpl.hpp"
#include "SymbolTable.hpp"
#include <stdexcept>
#include <cmath>

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
					ts_->putback(token);
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
				case TokenType::Mod:
				{
					if (double rhs = primary()) {
						lhs = std::fmod(lhs, rhs);
					}
					else {
						throw std::runtime_error("Invalid operand for mod operator");
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
			case TokenType::Name:
			{
				std::map<std::string, double>& table = getSymbolTable();

				std::string name = token.cvalue;

				if (table.find(name) == table.end()) {
					throw std::runtime_error("Name not found: " + token.cvalue);
				}

				token = ts_->getNextToken();

				// store new value
				if (token.type == TokenType::Equal) {
					table[name] = expression();
				}
				else {
						ts_->putback(token);
				}

				return table[name];
			}
			case TokenType::Plus:
					return primary();
			case TokenType::Minus:
					return -primary();
			default:
					throw std::runtime_error("Primary expected");
			}
		}

		double Parser::statement() {
			Token token = ts_->getNextToken();

			if (token.type == TokenType::Let) {
				return declaration();
			}
			else {
				ts_->putback(token);
				return expression();
			}
		}		

		double Parser::declaration() {
			// read name
			Token token = ts_->getNextToken();

			if (token.type != TokenType::Name) {
				throw std::runtime_error{"Name expected"};
			}

			std::string name = token.cvalue;

			// read equal sign
			token = ts_->getNextToken();

			if (token.type != TokenType::Equal) {
				throw std::runtime_error{"Missing equal operator"};
			}

			// read value
			double val = expression();

			// add to symbol table
			getSymbolTable()[name] = val;	

			return val;
		}

}
