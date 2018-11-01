#include "catch.hpp"
#include "Token.hpp"
#include "TokenStreamImpl.hpp"
#include <sstream>
#include <memory>

using namespace calculator;

TEST_CASE ("testSimpleExpression") {
	std::stringstream* ss{new std::stringstream("2+3.1*4")};
	std::unique_ptr<TokenStream> ts{new TokenStreamImpl};
	ts->setInputStream(&ss);

	Token expected = {TokenType::Numeric, 2};
	Token actual = ts->getNextToken();
	REQUIRE (expected.type ==  actual.type);
	REQUIRE (expected.nvalue ==  Approx(actual.nvalue));

	expected = {TokenType::Plus};
	actual = ts->getNextToken();
	REQUIRE (expected.type ==  actual.type);

	expected = {TokenType::Numeric, 3.1};
	actual = ts->getNextToken();
	REQUIRE (expected.type ==  actual.type);
	REQUIRE (expected.nvalue ==  Approx(actual.nvalue));

	expected = {TokenType::Mult};
	actual = ts->getNextToken();
	REQUIRE (expected.type ==  actual.type);

	expected = {TokenType::Numeric, 4};
	actual = ts->getNextToken();
	REQUIRE (expected.type ==  actual.type);
	REQUIRE (expected.nvalue ==  Approx(actual.nvalue));

	expected = {TokenType::Nul};
	actual = ts->getNextToken();
	REQUIRE (expected.type ==  actual.type);
}
