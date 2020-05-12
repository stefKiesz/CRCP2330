#pragma once

#include <iostream>
#include <map>

using namespace std;

class Assembler
{
public:
//translates code in table
	Assembler();

//returning binary code to dest
	string dest(string destAsm, unsigned long & lineNr);

//returning binary code to comp

	string comp(string compAsm, unsigned long & lineNr);

//returning binary code to jump
	string jump(string jumpAsm, unsigned long & lineNr);

private:
	map<string, string> destTable;
	map<string, string> compTable;
	map<string, string> jumpTable;
};

