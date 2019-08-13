#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <direct.h>
#include <windows.h>

int main() {
	FILE* fp;
	const int bufferSize = MAX_PATH;
	char oldDir[bufferSize]; // store the current directory
	char path[1035];

	fp = _popen("electron --version", "r");

	// wait until output is read
	while (fgets(path, sizeof(path) - 1, fp) != NULL) {}

	// if electron is not installed, must first be installed (assumes node is installed)
	if (path[0] != 'v') {
		printf("Electron is not installed!\n");
	}
	// electron is installed, proceed with program
	else {
		printf("Electron is installed!\n");
		system("run-electron.bat");
	}

	_pclose(fp);

	return 0;
}