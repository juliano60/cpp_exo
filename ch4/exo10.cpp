#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

// enter name-value pairs, then display them

int main() {
	std::cout << "Enter name-value pairs:\n";

	std::vector<std::string> names;
	std::vector<int> values;

	while (std::cin) {
		std::string name;
		int value;

		if (std::cin >> name >> value) {
			if (name == "NoName" && value == 0) {
				break;
			}

			// check for duplicates
			if (std::find(names.begin(), names.end(), name) != names.end()) {
				std::cerr << "Duplicate name found: " << name << "\n";
				continue;
			}

			names.push_back(name);
			values.push_back(value);	
		}
	}

	while (std::cin) {
		std::cout << "Enter name: ";

		std::string name;

		if (std::cin >> name) {
			auto it = std::find(names.begin(), names.end(), name);

			if (it != names.end()) {
				int ind = std::distance(names.begin(), it);

				std::cout << "Score: " << values[ind] << "\n";
			}		
			else {
				std::cerr << "Name not found.\n";
			}
		}
	}

	return 0;
}
		
