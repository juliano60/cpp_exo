#ifndef READER_HPP
#define READER_HPP

#include <vector>
#include <iostream>

// read a structured file with the following format
// {year 1991
// 		{month feb (day hour value) (day hour value) ...}
// 		{month dec (day hour value) (day hour value) ...}
// }

struct Day {
	Day();
	std::vector<int> values;	// temperatures for each hour
};

struct Month {
	Month();
	int month;					// month value [1:12]
	std::vector<Day> days;		// one value for each day [1:31]
};

struct Year {
	Year();
	int year;
	std::vector<Month> months;	// one value for each month [1:12]
};

// a day reading
struct Reading {
	int day;
	int hour;
	double temperature;
};

std::istream& operator>>(std::istream& in, Reading& r);
std::istream& operator>>(std::istream& in, Month& m);
std::istream& operator>>(std::istream& in, Year& y);

#endif
