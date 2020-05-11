#include <iostream>
#include <fstream>
#include <bitset>
/*Library Reference: http://www.cplusplus.com/reference/ */

using namespace std;

int main(int infoA, char infoB[]) {

	string inputFileName, outputFileName;
	
	int lineNumberROM, newAddress;
	
	unsigned long lineNumberSource;
	
	ofstream fout;

	if (infoA < 2 || infoA > 3) {
		cout << "Entry: " << infoB[0] << " <inputfilename.asm> ->" << endl;
		exit(1);
	}
	else {
		inputFileName = infoB[1];
		outputFileName = inputFileName.substr(0, inputFileName.length() - 4) + ".hack";

		if (infoA == 3) {
			outputFileName = infoB[2];
		}
	}

}