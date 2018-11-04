#include "PunctStream.hpp"
#include <iostream>
#include <vector>
#include <string>

int main() {
	PunctStream ps(std::cin);
	ps.whitespace(";:.");
	
	std::vector<std::string> words;
	for (std::string word; ps >> word;) {
		std::cout << "DEBUG: " << word << "\n";
		words.push_back(word);
	}

	for (const auto& x: words) {
		std::cout << x << "\n";
	}

	return 0;
}
