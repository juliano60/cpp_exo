#include <iostream>

// a date class implementation

namespace chrono {
	enum class Month {
		jan=1, feb, mar, apr,
		may, jun, jul, aug,
		sep, oct, nov, dec
	};

	class Date {
	public:
		// construct a default Date set to 1st Jan 2001
		Date();
		Date(int y, Month m, int d);

		class Invalid {};	// invalid Date exception

		int getYear() const;
		Month getMonth() const;
		int getDay() const;

	private:
		int year_;
		Month month_;
		int day_;
	};

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

	// Output Date using format (year,month,day)
	std::ostream& operator<<(std::ostream& out, const Date& a);

	// Read in Date using format (year,month,day)
	// The date supplied must be a valid date.
	// Throws an instance of Date::Invalid exception if the
	// values supplied are invalid.
	std::istream& operator>>(std::istream& in, Date& a);

}
	 
