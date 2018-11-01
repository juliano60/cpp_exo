#include "TokenStreamImpl.hpp"
#include <string>
#include <cassert>
#include <cctype>

namespace calculator {

	TokenStreamImpl::TokenStreamImpl():
		input_(&std::cin),
		ownsInput_{false},
		buffer_{TokenType::Nul},
		isFull_{false}
	{}

	TokenStreamImpl::~TokenStreamImpl() {
		if (ownsInput_) {
			delete input_;
		}
	}

	void TokenStreamImpl::setInputStream(std::istream* in) {
		input_ = in;
		ownsInput_ = true;
	}

	Token TokenStreamImpl::getNextToken() {
		if (isFull_) {
			isFull_ = false;
			return buffer_;
		}

		char ch = 0;

		// skip whitespace except newline
		while (input_->get(ch) && std::isspace(ch) && ch != '\n');

		switch (ch) {
		case '\0':
		case '\n':
			return Token{static_cast<TokenType>(ch)};
		case '0': case '1': case '2':
		case '3': case '4': case '5':
		case '6': case '7': case '8':
		case '9':
			{
				double num = 0.0;
				input_->putback(ch);

				(*input_) >> num;
				return Token{TokenType::Numeric, num};
			}
		case '+': case '-':
		case '*': case '/':
			return Token{static_cast<TokenType>(ch)};
		default:
			{
				std::string msg = "Invalid token: " + std::string{ch};
				throw std::runtime_error{msg};
			}
		}
	}

	void TokenStreamImpl::putback(Token token) {
		assert(!isFull_);

		buffer_ = token;
		isFull_ = true;
	}

}
