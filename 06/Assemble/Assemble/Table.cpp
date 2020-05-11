#include "Table.h"

using namespace std;

Table::Table() {

	AddressTable["SP"] = 0;
	AddressTable["LCL"] = 1;
	AddressTable["ARG"] = 2;
	AddressTable["THIS"] = 3;
	AddressTable["THAT"] = 4;

	AddressTable["R0"] = 0;
	AddressTable["R1"] = 1;
	AddressTable["R2"] = 2;
	AddressTable["R3"] = 3;
	AddressTable["R4"] = 4;
	AddressTable["R5"] = 5;
	AddressTable["R6"] = 6;
	AddressTable["R7"] = 7;
	AddressTable["R8"] = 8;
	AddressTable["R9"] = 9;
	AddressTable["R10"] = 10;
	AddressTable["R11"] = 11;
	AddressTable["R12"] = 12;
	AddressTable["R13"] = 13;
	AddressTable["R14"] = 14;
	AddressTable["R15"] = 15;

	AddressTable["SCREEN"] = 16384;
	AddressTable["KBD"] = 24576;

}


