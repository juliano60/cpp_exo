#include "Reader.hpp"
#include <string>
#include <stdexcept>
#include <vector>
#include <map>

namespace {
	const std::string monthMoniker = "month";
	const std::string yearMoniker = "year";
	constexpr int not_a_reading = -1;
	constexpr int days_per_month = 31+1;
	constexpr int hours_per_day = 24;
	constexpr int months_per_year = 12+1;

	const static std::map<std::string, int> monthInts = {
				std::make_pair("jan", 1),
				std::make_pair("feb", 2),
				std::make_pair("mar", 3),
				std::make_pair("apr", 4),
				std::make_pair("may", 5),
				std::make_pair("jun", 6),
				std::make_pair("jul", 7),
				std::make_pair("aug", 8),
				std::make_pair("sep", 9),
				std::make_pair("oct", 10),
				std::make_pair("nov", 11),
				std::make_pair("dec", 12)
	};

	int month_to_int(const std::string& m) {
		auto it = monthInts.find(m);

		if (it != monthInts.end()) {
			return it->second;
		}

		throw std::runtime_error{"Invalid month: " + m};
	}

}

Day::Day():
	values(hours_per_day, not_a_reading)
{}

Month::Month():
	days(days_per_month, Day{})
{}

Year::Year():
	months(months_per_year, Month{})
{}

std::istream& operator>>(std::istream& in, Reading& r) {
	char ch;

	if (in >> ch &&  ch != '(') {
		// does not look like the start of a temperature reading
		in.unget();
		in.clear(std::ios_base::failbit);
		return in;
	}

	char ch2;
	int day, hour;
	double value;

	in >> day >> hour >> value >> ch2;

	if (!in || ch2 != ')') {
		throw std::runtime_error{"Bad reading"};
	}

	r.day = day;
	r.hour = hour;
	r.temperature = value;

	return in;
}

void end_of_loop(std::istream& in, char terminator, const std::string& msg) {
	if (in.fail()) {
		in.clear();

		char ch;
		if (in >> ch && ch == terminator) {
			return;
		}
		throw std::runtime_error{msg};
	}
}

bool is_valid(const Reading r) {
	constexpr int min_hour = 0;
	constexpr int max_hour = 23;
	constexpr int min_day = 1;
	constexpr int max_day = 31;
	constexpr int min_temp = -300;
	constexpr int max_temp = 300;

	if (r.day < min_day || r.day > max_day) {
		return false;
	}
	if (r.hour < min_hour || r.hour > max_hour) {
		return false;
	}
	if (r.temperature < min_temp || r.temperature > max_temp) {
		return false;
	}

	return true;
}

std::istream& operator>>(std::istream& in, Month& m) {
	char ch;

	if (in >> ch && ch != '{') {
		// does not look like the start of a Month
		in.unget();
		in.clear(std::ios_base::failbit);
		return in;
	}

	std::string monthTag;
	std::string month;

	in >> monthTag >> month;
	if (!in || monthTag != monthMoniker) {
		throw std::runtime_error{"Bad value supplied"};
	}

	m.month = month_to_int(month);
	int duplicates = 0;
	int invalids = 0;

	for (Reading r; in >> r;) {
		if (is_valid(r)) {
			if (m.days[r.day].values[r.hour] != not_a_reading) {
				++duplicates;
			}
			m.days[r.day].values[r.hour] = r.temperature;
		}
		else {
			++invalids;
		}
	}

	if (invalids) {
		throw std::runtime_error{"invalid readings in month"};
	}
	if (duplicates) {
		throw std::runtime_error{"duplicates readings in month"};
	}

	end_of_loop(in, '}', "bad end of month");
	return in;
}	
	
std::istream& operator>>(std::istream& in, Year& y) {
	char ch;

	if (in >> ch && ch != '{') {
		// does this look like the start of a year
		in.unget();
		in.clear(std::ios_base::failbit);
		return in;
	}

	std::string yearTag;
	int year;

	in >> yearTag >> year;
	if (!in || yearTag != yearMoniker) {
		throw std::runtime_error{"Bad year"};
	}

	y.year = year;
	while (true) {
		Month m;

		if (!(in >> m)) {
			break;
		}
		y.months[m.month] = m;
	}

	end_of_loop(in, '}', "Bad end of year");
	return in;
}
	
