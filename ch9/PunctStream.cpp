#include "PunctStream.hpp"
#include <cctype>
#include <algorithm>

PunctStream::PunctStream(std::istream& in):
	source_{in},
	sensitive_{true}
{}

bool PunctStream::isWhitespace(char c) {
	return std::find(white_.begin(),
					white_.end(),
					c) != white_.end();
}

void PunctStream::whitespace(const std::string& w) {
	white_ = w;
}

void PunctStream::addWhite(char c) {
	if (!isWhitespace(c)) {
		white_ += c;
	}
}

void PunctStream::caseSensitive(bool b) {
	sensitive_ = b;
}

PunctStream& PunctStream::operator>>(std::string& s) {
	while (!(buffer_ >> s)) {
		if (buffer_.bad() || !source_.good()) {
			return *this;
		}

		buffer_.clear();

		// read next line into buffer
		std::string line;
		std::getline(source_, line);

		for (char& ch: line) {
			if (isWhitespace(ch)) {
				ch = ' ';
			}
			else if (!sensitive_) {
				ch = std::tolower(ch);
			}
		}

		buffer_.str(line);
	}

	return *this;
}

PunctStream::operator bool() {
	return !(source_.fail() || source_.bad()); 
}

