#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// print out total, smallest and greatest of a list of values

int main() {
	std::cout << "Enter distances: ";

	std::vector<double> distances;
	for (double temp; std::cin >> temp;) {
		distances.push_back(temp);
	}

	std::sort(distances.begin(), distances.end());

	if (distances.size()) {
		std::cout << "Smallest distance: " << distances[0] << "\n";
		std::cout << "Largest distance: " << distances[distances.size()-1] << "\n";

		double sum = std::accumulate(distances.begin(), distances.end(), 0.0);
		std::cout << "Total distance: " << sum << "\n";
		std::cout << "Mean distance: " << sum / distances.size() << "\n";
	}

	return 0;
}
