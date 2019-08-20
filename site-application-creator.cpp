#include <iostream>
#include <fstream>

using namespace std;

inline const char* const BoolToString(bool b) {
	return b ? "1" : "0";
}

int main() {
	FILE* fp;
	char path[1035];
	std::string siteUrl;
	bool fullscreen = false;

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

		// prompt user for URL
		cout << "Enter the URL of the Website: ";
		std::cin >> siteUrl;
		// prompt if fullscreen
		cout << "Would you like the application to be fullscreen? (y/n): ";
		string result;
		cin >> result;
		if (result == "y" || result =="Y" || result == "yes" || result =="Yes") {
			fullscreen = true;
		}

		// Verify siteUrl is a valid URL (https://stackoverflow.com/questions/38608116/how-to-check-a-specified-string-is-a-valid-url-or-not-using-c-code)

		// write URL to file (which is then imported by the electron main.js)
		std::ofstream out("electron-files/site.json");
		std::string jsonString;
		jsonString = "{\n\t\"url\":\"" + siteUrl + "\",\n\t\"fullscreen\":" + BoolToString(fullscreen) + "\n}";
		out << jsonString;
		out.close();

		// run electron main.js
		system("run-electron.bat");
	}

	return 0;
}