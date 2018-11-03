#include "catch.hpp"
#include "Reader.hpp"
#include <sstream>

TEST_CASE("testValidReading") {
	std::istringstream ss{"(1 1 68)"};

	Reading r;
	ss >> r;

	REQUIRE(r.day == 1);
	REQUIRE(r.hour == 1);
	REQUIRE(r.temperature == Approx(68));
}

TEST_CASE("testInvalidReading") {
	std::istringstream ss{"(1 "};

	Reading r;
	REQUIRE_THROWS_AS(ss >> r, std::runtime_error);
}

TEST_CASE("testValidMonth") {
	std::istringstream ss{"{month feb (1 1 64)}"};

	Month m;
	ss >> m;

	constexpr int feb = 2;
	constexpr int first_day = 1;
	constexpr int first_hour = 1;

	REQUIRE(m.month == feb);
	REQUIRE(m.days[first_day].values[first_hour] == Approx(64));
}

TEST_CASE("testBadEndOfMonth") {
	std::istringstream ss{"{month feb (1 1 64)*"};

	Month m;

	REQUIRE_THROWS_AS(ss >>m, std::runtime_error);
}

TEST_CASE("testInvalidMonthDuplicates") {
	std::istringstream ss{"{month feb (1 1 64) (1 1 56)}"};
		
	Month m;

	REQUIRE_THROWS_AS(ss >>m, std::runtime_error);
}

TEST_CASE("testInvalidMonthOutOfRange") {
	std::istringstream ss{"{month feb (0 1 64)}"};
		
	Month m;

	REQUIRE_THROWS_AS(ss >>m, std::runtime_error);
}

TEST_CASE("canReadAValidYear") {
	std::istringstream ss{"{year 1990 {month feb (1 1 64)}}"};

	Year y;
	ss >> y;

	constexpr int year = 1990;
	constexpr int feb = 2;
	constexpr int first_day = 1;
	constexpr int first_hour = 1;

	REQUIRE(y.year == year);
	REQUIRE(y.months[feb].days[first_day].values[first_hour] == Approx(64));
}
