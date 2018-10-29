#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

// find min, max, mode of a sequence of strings

std::string getMode(const std::vector<std::string>& values);

int main() {
	std::cout << "Enter a sequence of strings:\n";

	std::vector<std::string> words;
	for (std::string temp; std::cin >> temp;) {
		words.push_back(temp);
	}

	if (words.size()) {
		std::sort(words.begin(), words.end());

		std::cout << "Minimum: " << words[0] << "\n";
		std::cout << "Maximum: " << words[words.size()-1] << "\n";
		std::cout << "Mode: " << getMode(words) << "\n";
	}

	return 0;
}

std::string getMode(const std::vector<std::string>& values) {
	std::map<std::string, int> freqs;

	for (const auto& x: values) {
		++freqs[x];
	}

	int highest = 0;
	std::string mode = values[0];

	for (const auto& x: freqs) {
		if (x.second > highest) {
			highest = x.second;
			mode = x.first;
		}
	}

	return mode;
}
