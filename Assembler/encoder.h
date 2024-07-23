#ifndef ENCODER_H
#define ENCODER_H

#include <iostream>
#include <string>
using namespace std;

class encoder
{
public:
    encoder();  // constructor
    ~encoder(); // destructor

    static string instructionAddress(string z);
    static string translateToBinary(int z);

    static string Dest(string z);
    static string Comp(string z);
    static string Jump(string z);
};

#endif // ENCODER_H
