#include <iostream>
#include <fstream>
#include <bitset>
/*Library Reference: http://www.cplusplus.com/reference/ */

#include "Parser.h"
#include "Table.h"
#include "Assembler.h"

using namespace std;

int main(int infoA, char* infoB[]) {

//setup
	string inputFileName, outputFileName;

	int lineNumberROM, newAddress;

	unsigned long lineNumberSource;

	ofstream fout;

//setting instructions
	if (infoA < 2 || infoA > 3) {
		cout << "Entry: " << infoB[0] << " <inputfilename.asm> ->" << endl;
		exit(1);
	}
	else {
//setting input file
		inputFileName = infoB[1];
		outputFileName = inputFileName.substr(0, inputFileName.length() - 4) + ".hack";

		if (infoA == 3) {
			outputFileName = infoB[2];
		}
	}
//setting output file
	fout.open(outputFileName);

//if it didn't go through
	if (fout.fail()) {
		cout << "Could not translate file." << endl;
		exit(1);
	}

//commands
	Parser symbolSource(inputFileName);
	Table symbolTable;

	lineNumberSource = 0;
	lineNumberROM = 0;

	while (true) {
		symbolSource.nextLine(lineNumberSource);

		if (!symbolSource.Commands()) {
			break;
		}

		if (symbolSource.commandType(lineNumberSource) == 'A' || symbolSource.commandType(lineNumberSource) == 'C') {
			lineNumberROM++;
		}

		if (symbolSource.commandType(lineNumberSource) == 'L' && !symbolTable.contains(symbolSource.symbol())) {
			symbolTable.add(symbolSource.symbol(), lineNumberROM);
		}
	}

//translate
	Parser assemblySource(inputFileName);
	Assembler assemble;

	lineNumberSource = 0;   
	newAddress = 16;      

	while (true) {
		assemblySource.nextLine(lineNumberSource);

		if (!assemblySource.Commands()) {
			break;
		}

		if (assemblySource.commandType(lineNumberSource) == 'A') {
//A-instructions start with '0'.
			fout << '0';  

//if symbol is a number.
			if (assemblySource.symbol().find_first_not_of("0123456789") == string::npos) {
//string -> decimal # -> binary #.
				fout << bitset<15>(stoull(assemblySource.symbol(), nullptr)).to_string();
			}
			else {
//if symbol is a variable.
				if (!symbolTable.contains(assemblySource.symbol())) {
					symbolTable.add(assemblySource.symbol(), newAddress++);
				}
//address -> decimal # -> binary #.
				fout << bitset<15>(static_cast<unsigned long long>(symbolTable.returnAddress(assemblySource.symbol()))).to_string();
			}
			fout << endl;
		}
		else if (assemblySource.commandType(lineNumberSource) == 'C') {
//C-instructions start with "111".
			fout << "111";  
			fout << assemble.comp(assemblySource.compP(), lineNumberSource);
			fout << assemble.dest(assemblySource.destP(), lineNumberSource);
			fout << assemble.jump(assemblySource.jumpP(), lineNumberSource);
			fout << endl;
		}
	}

	fout.close();
	return 0;
}