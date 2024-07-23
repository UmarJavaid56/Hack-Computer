#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <map>
#include <unordered_map>

class symbolTable
{
public:
    symbolTable();
    ~symbolTable();

    bool contains(const std::string &symbol) const;

    // Add a new symbol with the next available address
    void addSymbol(const std::string &symbol);

    // Add a new symbol with a specific address (used for labels)
    void addSymbolLabel(const std::string &symbol, int address);

    // Get the address of a given symbol
    int getAddress(const std::string &symbol) const;

    std::unordered_map<std::string, int> table;

private:
    static int nextValue;
};

#endif // SYMBOL_TABLE_H
