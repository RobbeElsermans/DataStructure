
#include <iostream>
#include <fstream>
#include <ctime>
#include "../lib/L_System/include/LSystemInterpreter.hpp"

typedef enum Type{
    triangle,
    plant,
    dragon,
    hilbert,
    snowWindow,
    tree,
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
    Type type = tree;

    switch (type) {
        case triangle:
            createTriangle();
            break;
        case plant:
            createPlant();
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
    std::ofstream saveFile("../output/test"+fileExtention + std::to_string(time(0)) + ".txt", std::ios::out);

    for(char c : getValue)
        saveFile << c;

    saveFile.close();
}