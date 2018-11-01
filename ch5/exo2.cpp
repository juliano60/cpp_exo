#include <iostream>
#include <stdexcept>

// a program to do celsius to kelvin conversion

double ctok(double c);
double ktoc(double k);

int main() {
	try {
		std::cout << "Enter temperature followed by unit (c or k: ";

		double c = 0;
		char unit;

		if (std::cin >> c >> unit) {
			switch (unit) {
				case 'k':
				{
					double celsius = ktoc(c);
					std::cout << celsius << "c\n";

					break;
				}
				case 'c':
				{	
					double kelvin = ctok(c);

					std::cout << kelvin << "k\n";
					break;
				}
			}
	
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		return 1;
	}	

	return 0;
} 

// celsius temperature cannot be less than
// absolute zero (-273.15 Celsius).
double ctok(double c) {
	constexpr double min_celsius = -273.15;

	if (c < min_celsius) {
		throw std::invalid_argument("Celsius temperature is invalid");
	}

	return c + min_celsius;
}

// Kelvin temperature cannot be less than
// absolute zero (0 Kelvin).
double ktoc(double k) {
	constexpr double min_kelvin = 0;

	if (k < min_kelvin) {
		throw std::invalid_argument("Kelvin temperature is invalid");
	}

	return k - 273.15;
} 
