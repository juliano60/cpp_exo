#ifndef PUNCT_STREAM_HPP
#define PUNCT_STREAM_HPP

#include <iostream>
#include <string>
#include <sstream>

// a class to read space separated strings from input which
// gives the user the ability to define define additional
// 'space' characters.

class PunctStream {
public:
	PunctStream(std::istream& in);

	bool isWhitespace(char c);
	void whitespace(const std::string& s);
	void addWhite(char c);

	// when set to true returns words read as lowercase words.
	void caseSensitive(bool b);

	PunctStream& operator>>(std::string& s);
	operator bool();

private:
	std::istream& source_;
	std::string white_;
	bool sensitive_;
	std::istringstream buffer_;
};


#endif
