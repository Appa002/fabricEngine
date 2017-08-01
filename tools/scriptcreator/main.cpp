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

int addSourceFile(string name, string path) {
	ofstream oFile(path + name + ".cpp");

	if (!oFile)
		return 1;

	string fileContent;

	fileContent += "#include \"../header/" + name + ".hpp\"\n";
	fileContent += "#include <engine.hpp>\n";
	fileContent += "#include <gameobject.hpp>\n";
	fileContent += "#include <behavior.hpp>\n";
	fileContent += "\n";
	fileContent += "using namespace fabric;\n";
	fileContent += "\n";
	fileContent += "namespace game{\n";
	fileContent += "\n";

	fileContent += "void " + name + "::setup(){\n";
	fileContent += "	// Use this for inital setup\n";
	fileContent += "	}\n";

	fileContent += "void " + name + "::update(){\n";
	fileContent += "	// Use this for frame by frame logic\n";
	fileContent += "	}\n";
	fileContent += "}";


	oFile.write(fileContent.c_str(), fileContent.size());
	oFile.close();

	return 0;
}

int addHeaderFile(string name, string path) {
	ofstream oFile(path + name + ".hpp");

	if (!oFile)
		return 1;


	string upperName = name;
	for (unsigned int i = 0; i < name.size(); i++)
		upperName[i] = toupper(name[i]);

	string fileContent = "";

	fileContent += "#ifndef " + upperName + "_HPP" + "\n";
	fileContent += "#define " + upperName + "_HPP" + "\n";

	fileContent += "\n";

	fileContent += "#include <engine.hpp> \n";
	fileContent += "#include <gameobject.hpp>\n";
	fileContent += "#include <behavior.hpp>\n";
	fileContent += "\n";
	fileContent += "using namespace fabric;\n";
	fileContent += "\n";
	fileContent += "namespace game{\n";
	fileContent += "	class " + name + " : public GameObject{\n";
	fileContent += "	public:\n";
	fileContent += "		void setup();\n";
	fileContent += "		void update ();\n";
	fileContent += "	};\n";
	fileContent += "}\n";
	fileContent += "#endif";


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
	
	lhs = addSourceFile(input, "../../engine/game/scripts/source/");
	if (lhs == 0)
		cout << "... .cpp file has been created in 'scripts/source'" << endl;
	else
		cout << "... .cpp file could not be created in'scripts/source'" << endl;

	lhs = addHeaderFile(input, "../../engine/game/scripts/header/");
	if (lhs == 0)
		cout << "... .hpp file has been created in 'scripts/header'" << endl;
	else
		cout << "... .hpp file could not be created in'scripts/header'" << endl;
	
	cout << endl;
	cout << "Script has been added, your welcome" << endl;

	waitForExit();
	
	return 0;
}