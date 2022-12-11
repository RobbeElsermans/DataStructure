
#include <iostream>
#include <fstream>
#include <ctime>
#include "../lib/L_System/include/LSystemInterpreter.hpp"

int main() {
    //std::cout << "Hello, World!" << std::endl;

    //https://ibeach.github.io/turtle/
    const std::vector<char> axiom{'F', 'X'};
    const std::unordered_set<Production<char>> productions{
            Production<char>{'X', {'X', '+', 'Y', 'F', '+'}},
            Production<char>{'Y', {'-', 'F', 'X', '-', 'Y'}},
    };

    const std::unordered_set<char> alphabet{'X','Y','F','+','-'};

    //Drawing

    // F    means go forward by 20 px
    // -    means go left by 90°
    // +    means go right by 90°
    // X, Y means do nothing

    std::vector<char> getValue = LSystemInterpreter<char>(axiom, productions, alphabet).generate(13);

    //output getValue to file with timestamp
    std::ofstream saveFile("../output/test"+std::to_string(std::time(0))+".txt", std::ios::out);

    for(char c : getValue)
    saveFile << c;

    saveFile.close();
    return 0;
}
