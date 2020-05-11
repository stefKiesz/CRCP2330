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

bool Parser::Commands() {
	return !fin.eof();
}
//reading code until command found
void Parser::nextLine(unsigned long& lineNr) {
	string currentLine;
	unsigned long commentPos;
	bool commandFound;

	commandFound = false;

	while (!commandFound && getline(fin, currentLine)) {
		
		lineNr++;
		
		currentLine.erase(remove_if(currentLine.begin(), currentLine.end(), ::isspace), currentLine.end());

		commentPos = currentLine.find("//");
		if (commentPos != string::npos) {

			currentLine.erase(commentPos, currentLine.length() - commentPos);
		}
		commandFound = !currentLine.empty();
	}
	currentCommand = currentLine;
}

//searching command table
char Parser::commandType(unsigned long & lineNr) {

}
