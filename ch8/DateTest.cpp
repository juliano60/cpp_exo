#include "catch.hpp"
#include "Date.hpp"
#include <sstream>

using namespace chrono;

TEST_CASE("canCreateADefaultDate") {
	Date date;

	Date expected{2001, Month::jan, 1};
	REQUIRE(date == expected);
}

TEST_CASE("canOutputADate") {
	Date date{2011, Month::mar, 10};
	std::ostringstream ss;

	ss << date;

	std::string expected = "(2011,3,10)";
	REQUIRE(ss.str() == expected);
}

TEST_CASE("canReadADate") {
	std::string dateStr{"(2018,4,16)"};

	std::istringstream ss{dateStr};
	Date date;
	ss >> date;

	Date expected{2018, Month::apr, 16};
	REQUIRE(ss.good());
	REQUIRE(date == expected);
}

