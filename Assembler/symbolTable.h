#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <iostream>
#include <string.h>
#include <map>

class symbolTable
{
public:
    symbolTable();
    ~symbolTable();

    bool contains(const std::string &symbol) const;

    // Add a new symbol with the next available address
    void addSymbol(const std::string &symbol);

    // Add a new symbol with a specific address (used for labels)
    void addSymbol(const std::string &symbol, int address);

    // Get the address of a given symbol
    int getAddress(const std::string &symbol) const;

private:
    std::map<std::string, int> table;
    static int nextValue;
};

#endif