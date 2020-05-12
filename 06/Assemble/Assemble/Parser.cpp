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
	if (commandTable.find(currentCommand[0]) != commandTable.end()) {
		return commandTable[currentCommand[0]];
	}

	cout << "Invalid syntax: " << lineNr << endl;
	exit(1);
}

//setting symbol values
string Parser::symbol() {
	unsigned long openBracketPos, closeBracketPos;

	openBracketPos = currentCommand.find('(');
	closeBracketPos = currentCommand.find(')');

//returning to A-instruction
	if (currentCommand[0] == '@') {
		return currentCommand.substr(1, currentCommand.length() - 1);
	}
//returning to L-instruction
	else if (openBracketPos != string::npos && closeBracketPos != string::npos) {
		return currentCommand.substr(openBracketPos + 1, closeBracketPos - openBracketPos - 1);
	}
//return blank if error occurs
	return "";
}

//setting dest function
string Parser::destP() {
	unsigned long equalSignPos;

	equalSignPos = currentCommand.find('=');

	if (equalSignPos != string::npos) {
		return currentCommand.substr(0, equalSignPos);
	}
	return "";
}

//setting comp function
string Parser::compP() {
	unsigned long equalSignPos, semiColonPos;

	equalSignPos = currentCommand.find('=');
	semiColonPos = currentCommand.find(';');


	if (equalSignPos != string::npos) {
		if (semiColonPos != string::npos) {
//dest = comp ; jump
			return currentCommand.substr(equalSignPos + 1, semiColonPos - equalSignPos - 1);
		}
//dest = comp
		return currentCommand.substr(equalSignPos + 1, currentCommand.length() - equalSignPos - 1);
	}
	else if (semiColonPos != string::npos) {
//comp ; jump
		return currentCommand.substr(0, semiColonPos);
	}
	return "";
}

//setting jump function
string Parser::jumpP() {
	unsigned long semiColonPos;

	semiColonPos = currentCommand.find(';');

	if (semiColonPos != string::npos) {
		return currentCommand.substr(semiColonPos + 1, currentCommand.length() - semiColonPos - 1);
	}
	return "";
}
