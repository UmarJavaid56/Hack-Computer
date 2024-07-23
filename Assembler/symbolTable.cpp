#include "symbolTable.h"
#include <stdexcept>

int symbolTable::nextValue = 16;

symbolTable::symbolTable()
{
    table.insert(std::make_pair("R0", 0));
    table.insert(std::make_pair("R1", 1));
    table.insert(std::make_pair("R2", 2));
    table.insert(std::make_pair("R3", 3));
    table.insert(std::make_pair("R4", 4));
    table.insert(std::make_pair("R5", 5));
    table.insert(std::make_pair("R6", 6));
    table.insert(std::make_pair("R7", 7));
    table.insert(std::make_pair("R8", 8));
    table.insert(std::make_pair("R9", 9));
    table.insert(std::make_pair("R10", 10));
    table.insert(std::make_pair("R11", 11));
    table.insert(std::make_pair("R12", 12));
    table.insert(std::make_pair("R13", 13));
    table.insert(std::make_pair("R14", 14));
    table.insert(std::make_pair("R15", 15));
    table.insert(std::make_pair("SCREEN", 16384));
    table.insert(std::make_pair("KBD", 24576));
    table.insert(std::make_pair("SP", 0));
    table.insert(std::make_pair("LCL", 1));
    table.insert(std::make_pair("ARG", 2));
    table.insert(std::make_pair("THIS", 3));
    table.insert(std::make_pair("THAT", 4));
}

symbolTable::~symbolTable() {}

// Check if symbol already exists in table
bool symbolTable::contains(const std::string &symbol) const
{
    return table.find(symbol) != table.end();
}

// If symbol does not exist in table, add it to the next available address
void symbolTable::addSymbol(const std::string &symbol)
{
    if (!contains(symbol))
    {
        table[symbol] = nextValue++;
    }
}

// Add Label to table
void symbolTable::addSymbolLabel(const std::string &symbol, int address)
{
    table[symbol] = address;
}

int symbolTable::getAddress(const std::string &symbol) const
{
    auto it = table.find(symbol);
    if (it != table.end())
    {
        return it->second;
    }
    else
    {
        throw std::runtime_error("Symbol not found in the table");
    }
}
