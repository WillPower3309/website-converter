#include <iostream>
#include <fstream>

using namespace std;

int main() {
	FILE* fp;
	char path[1035];

	fp = _popen("electron --version", "r");

	// wait until output is read
	while (fgets(path, sizeof(path) - 1, fp) != NULL) {}
	_pclose(fp);

	// if electron is not installed, must first be installed (assumes node is installed)
	if (path[0] != 'v') {
		cout << "Electron is not installed!";
	}
	// electron is installed, proceed with program
	else {
		cout << "Electron is installed!\n";
		cout << "Enter the URL of the Website: ";

		// write URL to file (which is then imported by the electron main.js)
		std::string siteUrl;
		std::cin >> siteUrl;
		std::ofstream out("electron-files/url.txt");
		out << siteUrl;
		out.close();

		cout << "Converting " << siteUrl << " to Desktop App";

		// run electron main.js
		system("run-electron.bat");
	}

	return 0;
}