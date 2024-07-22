#include "symbolTable.h"
#include "string.h"

symbolTable::symbolTable()
{
    table.insert(std::pair<std::string, int>("R0", 0));
    table.insert(std::pair<std::string, int>("R1", 1));
    table.insert(std::pair<std::string, int>("R2", 2));
    table.insert(std::pair<std::string, int>("R3", 3));
    table.insert(std::pair<std::string, int>("R4", 4));
    table.insert(std::pair<std::string, int>("R5", 5));
    table.insert(std::pair<std::string, int>("R6", 6));
    table.insert(std::pair<std::string, int>("R7", 7));
    table.insert(std::pair<std::string, int>("R8", 8));
    table.insert(std::pair<std::string, int>("R9", 9));
    table.insert(std::pair<std::string, int>("R10", 10));
    table.insert(std::pair<std::string, int>("R11", 11));
    table.insert(std::pair<std::string, int>("R12", 12));
    table.insert(std::pair<std::string, int>("R13", 13));
    table.insert(std::pair<std::string, int>("R14", 14));
    table.insert(std::pair<std::string, int>("R15", 15));
    table.insert(std::pair<std::string, int>("SCREEN", 16384));
    table.insert(std::pair<std::string, int>("KBD", 24576));
    table.insert(std::pair<std::string, int>("SP", 0));
    table.insert(std::pair<std::string, int>("LCL", 1));
    table.insert(std::pair<std::string, int>("ARG", 2));
    table.insert(std::pair<std::string, int>("THIS", 3));
    table.insert(std::pair<std::string, int>("THAT", 4));
}

symbolTable::~symbolTable() {}

// check if symbol already exists in table
bool symbolTable::contains(const std::string &x) const
{
    return table.find(x) != table.end();
}

// If symbol does not exist in table, add it to the next available address
void symbolTable::addSymbol(const std::string &x)
{
    if (!contains)
    {
        table[x] = nextValue++;
    }
}

// Add Label to tabel
void symbolTable::addSymbolLabel(const std::string &x, int address)
{
    table[x] = address;
}

int symbolTable::getAddress(const std::string &x) const
{

    auto it = table.find(x);
    if (it != table.end())
    {
        return it->second;
    }
    else
    {
        throw std::runtime_error("Symbol not found in the table");
    }
}