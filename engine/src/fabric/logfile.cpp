#include <fabric/logfile.hpp>


int fabric::Logfile::open(std::string path) {
	
	int seconds = static_cast<int>(time(0));

	path = path + "/log_" + std::to_string(seconds) + ".txt";
	file.open(path, std::ios::app);
	
	std::cout << path << std::endl;

	if (!file.is_open()) {
		std::cout << "Could not create logfile in" << path << std::endl;
		return 1;
	}
		
	Logfile::basicLog("Fabric Engine Log");
	Logfile::basicLog("---Log Begin---" + std::string("\n"));

	return 0;
}

int fabric::Logfile::close() {
	file << "---Log End---" << std::endl;
	file.flush();
	file.close();
	return 0;
}

int fabric::Logfile::logout(std::string message) {

	Logfile::logout("NaN", 00, message, "[INFO]");
	return 0;
}

int fabric::Logfile::logout(std::string message, std::string type) {
	Logfile::logout("NaN", 00, message, type);

	return 0;
}

int fabric::Logfile::logout(const char* file, int line, std::string message, std::string type) {

	message = std::string(file) + "  " + std::to_string(line) + "  " + type + "  " + message;
	Logfile::basicLog(message);

	return 0;
}

int fabric::Logfile::basicLog(std::string message) {
	if (!file.is_open())
		return 1;

	file << message.c_str() << std::endl;
	file.flush();

	return 0;
}

fabric::Logfile::Logfile() {
}

fabric::Logfile::~Logfile() {

}
