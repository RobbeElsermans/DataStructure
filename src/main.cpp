
#include <iostream>
#include <fstream>
#include <ctime>
#include "../lib/L_System/include/LSystemInterpreter.hpp"

typedef enum Type{
    triangle = 1,
    plant = 2,
    dragon = 3,
    hilbert = 4,
    snowWindow = 5,
    tree = 6,
    numberLines = 7,
    weirdness = 8
}Type;

//Used methods
void createTriangle();
void createPlant();
void createTree();
void createDragon();
void createHilbert();
void createSnowWindow();
void createNumberLines();
void createWeirdness();
void CreateFile(std::vector<char> &getValue, const std::string& fileExtention);
void CreateFile(std::vector<int8_t> &getValue, const std::string& fileExtention);

int main() {
    Type type;

    //User input requested for generation
    std::cout << "Give a number accordingly of the list:" << std::endl;
    std::cout << "1: triangle"<< std::endl;
    std::cout << "2: plant"<< std::endl;
    std::cout << "3: dragon"<< std::endl;
    std::cout << "4: hilbert"<< std::endl;
    std::cout << "5: snowWindow"<< std::endl;
    std::cout << "6: tree"<< std::endl;
    std::cout << "7: numberLines"<< std::endl;
    std::cout << "8: weirdness"<< std::endl<< std::endl;
    std::cout << "number: ";

    char input;
    std::cin >> input;

    //source: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
    type = (Type)(input - '0');

    switch (type) {
        case triangle:
            createTriangle();
            break;
        case plant:
            createPlant();
            break;
        case dragon:
            createDragon();
            break;
        case hilbert:
            createHilbert();
            break;
        case snowWindow:
            createSnowWindow();
            break;
        case tree:
            createTree();
            break;
        case numberLines:
            createNumberLines();
            break;
        case weirdness:
            createWeirdness();
            break;
        default:
            std::cout << "Wrong input!" << std::endl;
    }

    return 0;
}

void createTree() {
//https://ibeach.github.io/turtle/

    const std::vector<char> axiom{'F'};
    const std::unordered_set<Production<char>> productions{
            Production<char>{'F', {'F','F', '-', '[', '-', 'F','+','F','+','F',']','+','[','+','F','-','F','-','F',']'}},
    };

    const std::unordered_set<char> alphabet{'F','+','-','[',']'};

    std::vector<char> getValue = LSystemInterpreter<char>(axiom, productions, alphabet).generate(4);

    CreateFile(getValue, "Tree");
}

void createTriangle(){
    //https://ibeach.github.io/turtle/
    const std::vector<char> axiom{'A'};
    const std::unordered_set<Production<char>> productions{
            Production<char>{'A', {'B','-','A','-','B'}},
            Production<char>{'B', {'A','+','B','+','A'}},
    };

    const std::unordered_set<char> alphabet{'A','B','+','-'};

    std::vector<char> getValue = LSystemInterpreter<char>(axiom, productions, alphabet).generate(6);

    CreateFile(getValue, "Triangle");
}

void createPlant(){
    //https://ibeach.github.io/turtle/
    const std::vector<char> axiom{'X'};
    const std::unordered_set<Production<char>> productions{
            //X → F+[[X]-X]-F[-FX]+X
            Production<char>{'X', {'F', '+', '[', '[', 'X', ']', '-', 'X', ']', '-', 'F', '[', '-', 'F','X', ']', '+','X'}},
            //F → FF
            Production<char>{'F', {'F', 'F'}},
    };

    const std::unordered_set<char> alphabet{'F','X','+','-','[',']'};

    std::vector<char> getValue = LSystemInterpreter<char>(axiom, productions, alphabet).generate(6);

    CreateFile(getValue, "Plant");
}

void createHilbert(){
    //https://ibeach.github.io/turtle/
    const std::vector<char> axiom{'A'};
    const std::unordered_set<Production<char>> productions{
            //X → F+[[X]-X]-F[-FX]+X
            Production<char>{'A', {'+','B','F','-','A','F','A','-','F','B','+'}},
            //F → FF
            Production<char>{'B', {'-','A','F','+','B','F','B','+','F','A','-'}},
    };

    const std::unordered_set<char> alphabet{'A','B','F','-','+'};

    std::vector<char> getValue = LSystemInterpreter<char>(axiom, productions, alphabet).generate(6);

    CreateFile(getValue, "Hilbert");
}

void createDragon(){
    //https://en.wikipedia.org/wiki/L-system
    const std::vector<char> axiom{'F'};
    const std::unordered_set<Production<char>> productions{
            Production<char>{'F', {'F','+','G'}},
            Production<char>{'G', {'F','-','G'}}
    };

    const std::unordered_set<char> alphabet{'F','G','+','-'};

    std::vector<char> getValue = LSystemInterpreter<char>(axiom, productions, alphabet).generate(10);

    CreateFile(getValue, "Dragon");
}

void createSnowWindow(){
    //https://ibeach.github.io/turtle/
    const std::vector<char> axiom{'F','-','F','-','F', '-', 'F'};
    const std::unordered_set<Production<char>> productions{
            Production<char>{'F', {'F','F','-','F','-','-','F','-','F'}}
    };

    const std::unordered_set<char> alphabet{'F','-','+'};

    std::vector<char> getValue = LSystemInterpreter<char>(axiom, productions, alphabet).generate(5);

    CreateFile(getValue, "SnowWindow");
}

void createWeirdness(){
    //https://ibeach.github.io/turtle/
    const std::vector<char> axiom{'f','+','-','f','F'};
    const std::unordered_set<Production<char>> productions{
            Production<char>{'F', {'F','+','F','-'}},
            Production<char>{'f', {'f','+','F','F'}}
    };

    const std::unordered_set<char> alphabet{'F','f','F','-','+'};

    std::vector<char> getValue = LSystemInterpreter<char>(axiom, productions, alphabet).generate(11);

    CreateFile(getValue, "Weirdness");
}

void createNumberLines(){
    //1 is tekenen
    //0 is niet tekenen maar wel verplaatsen
    //2 is naar rechts
    //3 is naar links
    const std::vector<int8_t> axiom{1};
    const std::unordered_set<Production<int8_t>> productions{
            Production<int8_t>{1, {1,0,0,0,2,1}},
            Production<int8_t>{0, {1,0,3,1}}
    };

    const std::unordered_set<int8_t> alphabet{0,1,2,3};

    std::vector<int8_t> getValue = LSystemInterpreter<int8_t>(axiom, productions, alphabet).generate(8);

    CreateFile(getValue, "Numberlines");
}

void CreateFile(std::vector<char> &getValue, const std::string& fileExtention) {//output getValue to file with timestamp
    std::string extention = fileExtention + std::to_string(time(0)) + ".txt";
    std::string outputFile = "../output/";
    std::ofstream saveFile(outputFile+extention, std::ios::out);

    for(char c : getValue)
        saveFile << c;

    std::cout << "file has been saved under \" "+ outputFile + "\" with name: "+ extention << std::endl;
    std::cout << "-->  "+ outputFile + extention << std::endl;
    std::cout << "Fill this path inside the Turtle.py file!" << std::endl;
    saveFile.close();
}

void CreateFile(std::vector<int8_t> &getValue, const std::string& fileExtention) {//output getValue to file with timestamp
    std::string extention = fileExtention + std::to_string(time(0)) + ".txt";
    std::string outputFile = "../output/";
    std::ofstream saveFile(outputFile+extention, std::ios::out);

    for(int8_t c : getValue)
        saveFile << std::to_string(c);

    std::cout << "file has been saved under \" "+ outputFile + "\" with name: "+ extention << std::endl;
    std::cout << "-->  "+ outputFile + extention << std::endl;
    std::cout << "Fill this path inside the Turtle.py file!" << std::endl;
    saveFile.close();
}