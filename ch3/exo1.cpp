#include <iostream>

// a program to convert miles to km
double convert_to_km(double miles);

int main() {
	std::cout << "Enter number of miles: ";

	double miles;

	if (std::cin >> miles) {
		double res = convert_to_km(miles);

		std::cout << "Kilometres: " << res << "\n";
	}

	return 0;
}

double convert_to_km(double miles) {
	constexpr double km_per_mile = 1.609;

	return miles * km_per_mile;
}
