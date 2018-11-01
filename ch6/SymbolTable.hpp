#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <map>
#include <string>

namespace calculator {
	std::map<std::string, double>& getSymbolTable();
}

#endif
