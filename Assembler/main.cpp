#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "assemblyParser.h"

using namespace std;

void removeCommentsAndWhitespace(vector<string> &lines)
{
    for (auto &line : lines)
    {
        // Remove comments
        string::size_type pos = line.find("//");
        if (pos != string::npos)
        {
            line = line.substr(0, pos);
        }

        // Remove whitespaces
        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
    }

    // Remove empty lines
    lines.erase(remove_if(lines.begin(), lines.end(), [](const string &line)
                          { return line.empty(); }),
                lines.end());
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Incorrect number of input arguments!!" << endl;
        return 1;
    }

    string input_file_name = argv[1];
    cout << "This is the input filename: " << input_file_name << endl;

    ifstream file(input_file_name);
    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << input_file_name << endl;
        return 1;
    }

    vector<string> file_contents;
    string line;
    while (getline(file, line))
    {
        file_contents.push_back(line);
    }
    file.close();

    cout << "Removing comments and whitespaces..." << endl;
    removeCommentsAndWhitespace(file_contents);

    AsmParser parser(file_contents);
    parser.processLines();
    vector<string> binary = parser.getBinaryOutput();

    int dot = input_file_name.find(".");
    string file_name = input_file_name.substr(0, dot);
    string output_file_name = file_name + ".hack";

    ofstream outfile(output_file_name, ofstream::out | ofstream::trunc);
    if (!outfile.is_open())
    {
        cerr << "Error: Could not open output file " << output_file_name << endl;
        return 1;
    }

    for (const auto &binary_line : binary)
    {
        outfile << binary_line << endl;
    }
    outfile.close();

    cout << "Output written to " << output_file_name << endl;

    return 0;
}
