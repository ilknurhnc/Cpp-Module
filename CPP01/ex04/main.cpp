#include <fstream>
#include <iostream>

int main(int ac, char *av[])
{
    if(ac != 4)
    {
        std::cout << "Usage: ./replace <filename> <s1> <s2>\n";
        return 1;
    }

    std::string inputFile = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.empty() || s2.empty() || inputFile.empty())
    {
        std::cout << "Error: string cannot be empty.\n";
        return 1;
    }

    std::ifstream infile(inputFile);
    if (!infile) {
        std::cout << "Error: Cannot open input file.\n";
        return 1;
    }

    std::ofstream outfile(inputFile + ".replace");
    if (!outfile) {
        std::cout << "Error: Cannot create output file.\n";
        return 1;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outfile << line << '\n';
    }

    infile.close();
    outfile.close();

    std::cout << "Replacement done. Output: " << inputFile << ".replace" << std::endl;
    return 0;

}