#include <iostream>
#include <cmath>

// a program to estimate the number of squares required
// for various values of grains of rice

double calculate_rice(double square);

int main() {
	double rice_wanted = 10e20;
	double rice_total;
	double square = 1;

	while (true) {
		rice_total = calculate_rice(square);

		/*if (rice_total > std::numeric_limits<int>::max()) {
			std::cout << "Largest number of square for int result: " << square << "\n";
			break;
		}*/

		if (rice_total == std::numeric_limits<double>::infinity()) {
			std::cout << "Largest number of square for double result: " << square << "\n";
			break;
		}

		std::cout << "[DEBUG] - Current : " << rice_total << "\n";
		++square;
	}

	return 0; 
}

double calculate_rice(double square) {
	if (square < 0) {
		throw std::runtime_error("Invalid input");
	}
	
	double total = 0;
	for (int i = 0; i != square; ++i) {
		total += std::pow(2, i);
	}

	return total;
}
