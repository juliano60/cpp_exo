#include "Date.hpp"

namespace {
}

namespace chrono {

	Date& getDefaultDate() {
		static Date defaultDate(2001, Month::jan, 1);

		return defaultDate;
	}

	Date::Date():
		year_{getDefaultDate().getYear()},
		month_{getDefaultDate().getMonth()},
		day_{getDefaultDate().getDay()}
	{}

	Date::Date(int y, Month m, int d):
		year_{y},
		month_{m},
		day_{d}
	{}

	int Date::getYear() const {
		return year_;
	}

	Month Date::getMonth() const {
		return month_;
	}

	int Date::getDay() const {
		return day_;
	}

	bool operator==(const Date& a, const Date& b) {
		return a.getYear() == b.getYear() &&
				a.getMonth() == b.getMonth() &&
				a.getDay() == b.getDay();
	}

	bool operator!=(const Date& a, const Date& b) {
		return !(a == b);
	}

	std::ostream& operator<<(std::ostream& out, const Date& a) {
		out << "("
			<< a.getYear() << ","
			<< static_cast<int>(a.getMonth()) << ","
			<< a.getDay() << ")";

		return out;	
	}

	std::istream& operator>>(std::istream& in, Date& a) {
		char ch1, ch2, ch3, ch4;
		int year, month, day;

		in >> ch1 >> year >> ch2 >> month >> ch3 >> day >> ch4;

		if (!in) {
			return in;
		}

		// validate format
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
			in.clear(std::ios_base::failbit);
			return in;
		}

		a = Date{year,static_cast<Month>(month),day};

		return in;
	}

}	
