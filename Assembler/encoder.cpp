#include "encoder.h"

encoder::encoder() {}

encoder::~encoder() {}

string encoder::instructionAaddress(string z)
{
    return translateToBinary(stoi(z));
}

string encoder::translateToBinary(int z)
{
    string address = "";
    int i = z;

    // Get length of Integer in Binary Code (divide by 2)
    while (i > 0)
    {
        string temp = to_string(i % 2);
        address = temp + address;
        i = i / 2;
    }

    // Add the remaining empty bits
    if (address.length() < 16)
        address = string(16 - address.length(), '0') + address;

    return address;
}

string encoder::Dest(string z)
{
    string translate;
    if (z == "null")
    {
        translate = "000";
    }
    else if (z == "M")
    {
        translate = "001";
    }
    else if (z == "D")
    {
        translate = "010";
    }
    else if (z == "MD")
    {
        translate = "011";
    }
    else if (z == "A")
    {
        translate = "100";
    }
    else if (z == "AM")
    {
        translate = "101";
    }
    else if (z == "AD")
    {
        translate = "110";
    }
    else if (z == "AMD")
    {
        translate = "111";
    }
    else
    {
        translate = "000"; // Default value for invalid input
    }

    return translate;
}

string encoder::Comp(string z)
{
    string translate;

    if (z == "0")
    {
        translate = "0101010";
    }
    else if (z == "1")
    {
        translate = "0111111";
    }
    else if (z == "-1")
    {
        translate = "0111010";
    }
    else if (z == "D")
    {
        translate = "0001100";
    }
    else if (z == "A")
    {
        translate = "0110000";
    }
    else if (z == "!D")
    {
        translate = "0001101";
    }
    else if (z == "!A")
    {
        translate = "0110001";
    }
    else if (z == "-D")
    {
        translate = "0001111";
    }
    else if (z == "-A")
    {
        translate = "0110011";
    }
    else if (z == "D+1" || z == "1+D")
    {
        translate = "0011111";
    }
    else if (z == "A+1" || z == "1+A")
    {
        translate = "0110111";
    }
    else if (z == "D-1")
    {
        translate = "0001110";
    }
    else if (z == "A-1")
    {
        translate = "0110010";
    }
    else if (z == "D+A" || z == "A+D")
    {
        translate = "0000010";
    }
    else if (z == "D-A")
    {
        translate = "0010011";
    }
    else if (z == "A-D")
    {
        translate = "0000111";
    }
    else if (z == "D&A" || z == "A&D")
    {
        translate = "0000000";
    }
    else if (z == "D|A" || z == "A|D")
    {
        translate = "0010101";
    }
    else if (z == "M")
    {
        translate = "1110000";
    }
    else if (z == "!M")
    {
        translate = "1110001";
    }
    else if (z == "-M")
    {
        translate = "1110011";
    }
    else if (z == "M+1" || z == "1+M")
    {
        translate = "1110111";
    }
    else if (z == "M-1")
    {
        translate = "1110010";
    }
    else if (z == "D+M" || z == "M+D")
    {
        translate = "1000010";
    }
    else if (z == "D-M")
    {
        translate = "1010011";
    }
    else if (z == "M-D")
    {
        translate = "1000111";
    }
    else if (z == "D&M" || z == "M&D")
    {
        translate = "1000000";
    }
    else if (z == "D|M" || z == "M|D")
    {
        translate = "1010101";
    }
    else
    {
        translate = "000000"; // Default value for invalid input
    }

    return translate;
}

string encoder::Jump(string z)
{
    string translate;

    if (z == "null")
    {
        translate = "000";
    }
    else if (z == "JGT")
    {
        translate = "001";
    }
    else if (z == "JEQ")
    {
        translate = "010";
    }
    else if (z == "JGE")
    {
        translate = "011";
    }
    else if (z == "JLT")
    {
        translate = "100";
    }
    else if (z == "JNE")
    {
        translate = "101";
    }
    else if (z == "JLE")
    {
        translate = "110";
    }
    else if (z == "JMP")
    {
        translate = "111";
    }
    else
    {
        translate = "000"; // Default value for invalid input
    }

    return translate;
}
