#ifndef ASSEMBLY_PARSER_H
#define ASSEMBLY_PARSER_H

#include <iostream>
#include <string>
#include <vector>
#include "encoder.h"
#include "symbolTable.h"

using namespace std;

class AsmParser
{
private:
    vector<string> sourceCodeLines;
    vector<string> binaryCode;
    symbolTable symbolTable;

public:
    AsmParser(vector<string> source) { sourceCodeLines = source; }
    ~AsmParser();

    void processLines();

    void firstPass();  // Checks for labels only
    void secondPass(); // Checks for @ symbols

    vector<string> getBinaryOutput();

    int getCommandType(const string &line);

    string getSymbol(int commandType, const string &line);

    string getDestMnemonic(int commandType, const string &line);
    string getCompMnemonic(int commandType, const string &line);
    string getJumpMnemonic(int commandType, const string &line);

    bool isNumeric(const string &str);
};

#endif // ASSEMBLY_PARSER_H
