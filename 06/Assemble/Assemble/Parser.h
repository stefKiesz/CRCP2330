#pragma once


#ifndef ASSEMBLER_PARSER_H
// Define directive: https://stackoverflow.com/questions/135069/ifdef-vs-if-which-is-better-safer-as-a-method-for-enabling-disabling-compila
#define ASSEMBLER_PARSER_H

#include <iostream>
#include <fstream>

#include <string>
// Algorithm reference: http://www.cplusplus.com/reference/algorithm/
#include <algorithm>
// Map reference: https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
#include <map>

using namespace std;

class Parser{
public:

//opening input file
	Parser(string & fileName);

//condition of returning true if file has commands need to be parsed
	bool Commands();

//reads the next command to be parsed
	void nextLine(unsigned long& lineNr);

//returning type of command
	char commandType(unsigned long& lineNr);

};
#endif // !ASSEMBLER_PARSER_H



