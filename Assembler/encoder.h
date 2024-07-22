#include <iostream>
#include <string.h>
using namespace std;

class encoder
{
public:
    encoder();  // constructor
    ~encoder(); // destructor

    static string instructionAaddress(string z);
    static string translateToBinary(int z);

    static string Dest(string z);
    static string Comp(string z);
    static string Jump(string z);
};