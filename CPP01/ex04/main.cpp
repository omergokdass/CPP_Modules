#include <iostream>
#include <fstream>
#include <string>

static std::string replaceString( const std::string &content, const std::string &s1, const std::string &s2 ) {
	if (s1.empty())
		return content;

	std::string result;
	std::size_t startPos = 0;
	std::size_t foundPos;

	while ((foundPos = content.find(s1, startPos)) != std::string::npos) {
		result.append(content, startPos, foundPos - startPos);
		result.append(s2);
		startPos = foundPos + s1.length();
	}
	result.append(content, startPos, std::string::npos);
	return result;
}

int main( int ac, char **av ) {
	if (ac != 4) {
		std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	std::ifstream inFile(filename.c_str());
	if (!inFile.is_open()) {
		std::cerr << "Error: Could not open input file" << filename << std::endl;
		return 1;
	}

	std::string content;
	std::string line;
	while (std::getline(inFile, line)) {
		content += line;
		if (!inFile.eof()) {
			content += "\n";
		}
	}
	inFile.close();

	std::string replacedContent = replaceString(content, s1, s2);

	std::string outFilename = filename + ".replace";
	std::ofstream outFile(outFilename.c_str());
	if (!outFile.is_open()) {
		std::cerr << "Error: Could not create output file '" << outFilename << "'" << std::endl;
		return 1;
	}

	outFile << replacedContent;
	outFile.close();

	return 0;
}
