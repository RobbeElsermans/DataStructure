cmake_minimum_required(VERSION 3.23)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

#add_library(DataStructure STATIC
#        "lib/..."
#        "lib..."
#        )

#target_include_directories(DataStructure PUBLIC
#        "include/"
#        )
#

add_library(lSystemLib STATIC
        "src/LSystem/Production.cpp"
        src/LSystem/Production.cpp include/LSystem/Production.h src/LSystem/Validation.cpp include/LSystem/Validation.h src/LSystem/LSystemInterpreter.cpp include/LSystem/LSystemInterpreter.h)

target_include_directories(lSystemLib PUBLIC "include/")

add_executable(main
        "src/main.cpp"
        src/LSystem/Production.cpp include/LSystem/Production.h src/LSystem/Validation.cpp include/LSystem/Validation.h src/LSystem/LSystemInterpreter.cpp include/LSystem/LSystemInterpreter.h)

target_include_directories(main PUBLIC
        "include/"
        )

add_executable(TestSuite
        "test/main.cpp"
        src/LSystem/Production.cpp include/LSystem/Production.h src/LSystem/Validation.cpp include/LSystem/Validation.h src/LSystem/LSystemInterpreter.cpp include/LSystem/LSystemInterpreter.h test/Production/U_Production.cpp)

target_include_directories(TestSuite PUBLIC
        "include/"
        )


target_link_libraries(TestSuite PUBLIC lSystemLib)
target_link_libraries(main PUBLIC lSystemLib)