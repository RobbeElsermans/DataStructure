cmake_minimum_required(VERSION 3.23)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_library(lSystemLib STATIC
        "lib/L_System/src/Production.cpp"
        lib/L_System/src/Production.cpp
        lib/L_System/include/Production.hpp
        lib/L_System/src/Validation.cpp
        lib/L_System/include/Validation.hpp
        lib/L_System/src/LSystemInterpreter.cpp
        lib/L_System/include/LSystemInterpreter.hpp
        lib/L_System/src/HelpFunctions.cpp
        lib/L_System/include/HelpFunctions.hpp)

target_include_directories(lSystemLib PUBLIC "include/")

add_library(TurtleLib STATIC
        lib/Turtle/src/Turtle.cpp
        lib/Turtle/include/Turtle.h)

target_include_directories(TurtleLib PUBLIC "include/")

add_executable(main
        "src/main.cpp"
        lib/L_System/src/Production.cpp
        lib/L_System/include/Production.hpp
        lib/L_System/src/Validation.cpp
        lib/L_System/include/Validation.hpp
        lib/L_System/src/LSystemInterpreter.cpp
        lib/L_System/include/LSystemInterpreter.hpp
        lib/L_System/src/HelpFunctions.cpp
        lib/L_System/include/HelpFunctions.hpp lib/Turtle/src/Turtle.cpp lib/Turtle/include/Turtle.h)

target_include_directories(main PUBLIC
        "include/"
        "lib/"
        )

add_executable(TestSuite
        "test/main.cpp"
        test/L_System/U_Production.cpp
        test/L_System/U_Validation.cpp
        test/L_System/U_HelpFunctions.cpp
        test/L_System/U_LSystemInterpreter.cpp lib/Turtle/src/Turtle.cpp lib/Turtle/include/Turtle.h)

target_include_directories(TestSuite PUBLIC
        "include/"
        )


target_link_libraries(TestSuite PUBLIC lSystemLib)
target_link_libraries(main PUBLIC lSystemLib)