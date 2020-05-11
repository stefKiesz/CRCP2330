#include "Parser.h"

using namespace std;

Parser::Parser(string & fileName) {
//opening input file
	fin.open(fileName);

//condition if not run
	if (fin.fail()) {
		cout << fileName << "not found." << endl;
		exit(1);
	}

	//Setting command table
	commandTable['@'] = 'A';


	commandTable['A'] = 'C';
	commandTable['D'] = 'C';
	commandTable['M'] = 'C';
	commandTable['0'] = 'C';
	commandTable['1'] = 'C';
	commandTable['-'] = 'C';
	commandTable['!'] = 'C';

	commandTable['('] = 'L';
}