#include "SymbolTable.hpp"

namespace calculator {
	std::map<std::string, double>& getSymbolTable() {
		static std::map<std::string, double> table;

		return table;
	}
}
