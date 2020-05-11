#pragma once
#ifndef ASSEMBLER_TABLE_H
#define ASSEMBLER_TABLE_H

#include <iostream>
#include <map>

using namespace std;

class Table{

public:

//initializing map
	Table();

//adding values to table
	void add(string symbol, int address);

//containing values to table if true
	bool contains(string symbol);

//returning address
	int returnAddress(string symbol);

private:
	map <string, int> AddressTable;

};
#endif // !ASSEMBLER_TABLE_H


