
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
};

void createTriangle();
void createPlant();
void createDragon();
void createHilbert();
void createSnowWindow();

void CreateFile(std::vector<char> &getValue, const std::string& fileExtention);

void createTree();

int main() {
    //std::cout << "Hello, World!" << std::endl;
    Type type;// = tree;

    std::cout << "Give a number accordingly of the list:" << std::endl;
    std::cout << "1: triangle"<< std::endl;
    std::cout << "2: plant"<< std::endl;
    std::cout << "3: dragon"<< std::endl;
    std::cout << "4: hilbert"<< std::endl;
    std::cout << "5: snowWindow"<< std::endl;
    std::cout << "6: tree"<< std::endl<< std::endl;
    char input;
    std::cout << "number: ";
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
    const std::vector<char> axiom{'L'};
    const std::unordered_set<Production<char>> productions{
            Production<char>{'L', {'[','R', '-', 'L', '-', 'R',']'}},
            Production<char>{'R', {'L', '+', 'R', '+', 'L'}},
    };

    const std::unordered_set<char> alphabet{'R','L','+','-','[',']'};

    std::vector<char> getValue = LSystemInterpreter<char>(axiom, productions, alphabet).generate(10);

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

    const std::unordered_set<char> alphabet{'A','B','F','-','+'};

    std::vector<char> getValue = LSystemInterpreter<char>(axiom, productions, alphabet).generate(4);

    CreateFile(getValue, "SnowWindow");
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