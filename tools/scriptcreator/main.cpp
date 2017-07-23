#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string tok;

	while (getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}

	return internal;
}


int addIncludeHeader(string name, char* path) {
	ifstream iFile(path);
	string str;
	string fileContent = "";

	if (!iFile)
		return 1;

	while (!iFile.eof())
	{
		getline(iFile, str);

		str += "\n";
		fileContent += str;

		str = "";
	}

	iFile.close();

	vector<string> befor = split(fileContent, '\n');
	vector<string> after;

	for (unsigned int i = 0; i < befor.size(); i++) {
		after.push_back(befor.at(i));

		if (befor.at(i) == "//HEADER") {
			after.push_back("#include <scripts/" + name + ".hpp>");
		}
	}

	fileContent = "";

	for (unsigned int i = 0; i < after.size(); i++) {
		fileContent += after.at(i) + "\n";
	}


	//cout << fileContent << endl;


	ofstream oFile(path);

	oFile.write(fileContent.c_str(), fileContent.size());
	oFile.close();
	return 0;
}


int addEngineRegister(string name, char* path) {
	ifstream iFile(path);
	string str;
	string fileContent = "";

	if (!iFile)
		return 1;

	while (!iFile.eof())
	{
		getline(iFile, str);

		str += "\n";
		fileContent += str;

		str = "";
	}

	iFile.close();

	vector<string> befor = split(fileContent, '\n');
	vector<string> after;

	for (unsigned int i = 0; i < befor.size(); i++) {
		after.push_back(befor.at(i));

		if (befor.at(i) == "//ENGINE_REGISTER") {

			string lowerName = name;
			for (unsigned int i = 0; i < name.size(); i++)
				lowerName[i] = tolower(name[i]);

			after.push_back("	game::" + name + "* " + lowerName + " new game::" + name + "();");
			after.push_back("	fabric::Engine::vRegisteredGameObjects->push_back(" + lowerName + ");");
			after.push_back(" ");
		}
	}

	fileContent = "";

	for (unsigned int i = 0; i < after.size(); i++) {
		fileContent += after.at(i) + "\n";
	}

	//cout << fileContent;

	ofstream oFile(path);

	oFile.write(fileContent.c_str(), fileContent.size());
	oFile.close();
	return 0;
}


int addSourceFile(string name, string path) {
	ofstream oFile(path + name + ".cpp");

	string fileContent = "";

	fileContent += "#include <engine.hpp>\n";
	fileContent += "#include <gameobject.hpp>\n";
	fileContent += "#include <behavior.hpp>\n";
	fileContent += "\n";
	fileContent += "using namespace fabric;\n";
	fileContent += "\n";
	fileContent += "namespace game{\n";
	fileContent += "	class " + name + " : public GameObject{\n";
	fileContent += "	public:\n";
	fileContent += "		// Use for initialization\n";
	fileContent += "		void setup(){\n";
	fileContent += "\n";
	fileContent += "		}\n";
	fileContent += "\n";
	fileContent += "		// Use for frame by frame logic\n";
	fileContent += "		void update (){\n";
	fileContent += "\n";
	fileContent += "		}\n";
	fileContent += "	};\n";
	fileContent += "}";


	oFile.write(fileContent.c_str(), fileContent.size());
	oFile.close();

	return 0;
}


void waitForExit() {
	string input;

	do {
		cout << "Input anything to exit: ";
		cin >> input;
	} while (input == "");
	
}


int main() {
	string input;
	int lhs;

	cout << "Welcome to the automated script creation tool" << endl;
	cout << "Is this tool beeing ran from the 'tools' directory in your project or" << endl;
	cout << "has been launched from the editor? [yes | no]: ";

	cin >> input;
	if (input == "no") {
		cout << "Please launched the tool from the 'tools' directory or the editor" << endl;
		waitForExit();
		return 1;
	}

	cout << endl;
	cout << "Please enter the name of your script (no exstenion): ";
	cin >> input;
	cout << "Thank You";
	cout << endl;

	lhs = addIncludeHeader(input, "../../game/game.cpp");
	if (lhs == 0)
		cout << "... Include headers have been created in 'game.cpp'" << endl;
	else
		cout << "... Include header could not be written to 'game.cpp'" << endl;

	
	lhs = addEngineRegister(input, "../../game/game.cpp");
	if (lhs == 0)
		cout << "... Engine register have been created in 'game.cpp'" << endl;
	else
		cout << "... Engine register could not be written to 'game.cpp'" << endl;

	
	lhs = addSourceFile(input, "../../game/scripts/source/");
	if (lhs == 0)
		cout << "... .cpp file has been created in 'scripts/source'" << endl;
	else
		cout << "... .cpp file could not be created in'scripts/source'" << endl;
	
	cout << endl;
	cout << "Script has been added, your welcome" << endl;

	waitForExit();
	
	return 0;
}