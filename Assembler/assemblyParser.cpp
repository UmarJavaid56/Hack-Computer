#include "assemblyParser.h"

AsmParser::~AsmParser() {}

void AsmParser::processLines()
{
    firstPass();
    secondPass();

    string temp;
    string out;
    int type;
    vector<string>::iterator it = sourceCodeLines.begin();

    while (it != sourceCodeLines.end())
    {
        temp = *it;
        type = getCommandType(temp);

        if (type == 1)
        {
            string sym;
            sym = getSymbol(type, temp);
            if (isNumeric(sym))
            {
                out = encoder::instructionAddress(sym);
                out = "0" + out;
                binaryCode.push_back(out);
            }
            else
            {
                int address = symbolTable.getAddress(sym);
                out = encoder::translateToBinary(address);
                out = "0" + out;
                binaryCode.push_back(out);
            }
        }
        else if (type == 2)
        {
            string c;
            string d;
            string j;
            string cdj;
            c = getCompMnemonic(type, temp);
            d = getDestMnemonic(type, temp);
            j = getJumpMnemonic(type, temp);
            cdj = encoder::Comp(c) + encoder::Dest(d) + encoder::Jump(j);
            out = "111" + cdj;
            binaryCode.push_back(out);
        }

        it++;
    }
}

void AsmParser::firstPass()
{
    string temp;
    int type;
    vector<string>::iterator it = sourceCodeLines.begin();

    int rom_line_count = 0;

    while (it != sourceCodeLines.end())
    {
        temp = *it;
        type = getCommandType(temp);

        string sym;
        sym = getSymbol(type, temp);

        if (type == 3)
        {
            if (!symbolTable.contains(sym))
            {
                symbolTable.addSymbolLabel(sym, rom_line_count);
                rom_line_count--;
            }
        }

        it++;
        rom_line_count++;
    }
}

void AsmParser::secondPass()
{
    string temp;
    int type;
    vector<string>::iterator it = sourceCodeLines.begin();

    while (it != sourceCodeLines.end())
    {
        temp = *it;
        type = getCommandType(temp);

        string sym;
        sym = getSymbol(type, temp);

        if (type == 1)
        {
            if (!isNumeric(sym))
            {
                if (!symbolTable.contains(sym))
                {
                    symbolTable.addSymbol(sym);
                }
            }
        }

        it++;
    }
}

vector<string> AsmParser::getBinaryOutput()
{
    return binaryCode;
}

int AsmParser::getCommandType(const string &line)
{
    int type = 0;

    // A_COMMAND = 1
    // C_COMMAND = 2
    // L_COMMAND = 3

    if (line.find("@") != string::npos)
    {
        type = 1;
    }
    else if (line.find("=") != string::npos || line.find(";") != string::npos)
    {
        type = 2;
    }
    else if (line.find("(") != string::npos)
    {
        type = 3;
    }

    return type;
}

string AsmParser::getSymbol(int commandType, const string &line)
{
    string symbol;

    if (commandType == 1)
    {
        symbol = line.substr(1);
    }
    else if (commandType == 3)
    {
        int bracket = line.find(")");
        symbol = line.substr(1, bracket - 1);
    }

    return symbol;
}

string AsmParser::getDestMnemonic(int commandType, const string &line)
{
    string dest;

    if (commandType == 2)
    {
        if (line.find("=") != string::npos)
        {
            int equals = line.find("=");
            dest = line.substr(0, equals);
        }
        else if (line.find(";") != string::npos)
        {
            dest = "null";
        }
    }

    return dest;
}

string AsmParser::getCompMnemonic(int commandType, const string &line)
{
    string comp;

    if (commandType == 2)
    {
        if (line.find("=") != string::npos)
        {
            int equals = line.find("=");
            comp = line.substr(equals + 1);
        }
        else if (line.find(";") != string::npos)
        {
            int semi_colon = line.find(";");
            comp = line.substr(0, semi_colon);
        }
    }

    return comp;
}

string AsmParser::getJumpMnemonic(int commandType, const string &line)
{
    string jump;

    if (commandType == 2)
    {
        if (line.find("=") != string::npos)
        {
            jump = "null";
        }
        else if (line.find(";") != string::npos)
        {
            int semi_colon = line.find(";");
            jump = line.substr(semi_colon + 1);
        }
    }

    return jump;
}

bool AsmParser::isNumeric(const string &str)
{
    for (char ch : str)
    {
        if (!isdigit(ch))
        {
            return false;
        }
    }
    return true;
}
