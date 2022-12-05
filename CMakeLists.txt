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
        "lib/L_System/src/Production.cpp"
        lib/L_System/src/Production.cpp lib/L_System/include/Production.h lib/L_System/src/Validation.cpp lib/L_System/include/Validation.h lib/L_System/src/LSystemInterpreter.cpp lib/L_System/include/LSystemInterpreter.h)

target_include_directories(lSystemLib PUBLIC "include/")

add_executable(main
        "src/main.cpp"
        lib/L_System/src/Production.cpp lib/L_System/include/Production.h lib/L_System/src/Validation.cpp lib/L_System/include/Validation.h lib/L_System/src/LSystemInterpreter.cpp lib/L_System/include/LSystemInterpreter.h)

target_include_directories(main PUBLIC
        "include/"
        )

add_executable(TestSuite
        "test/main.cpp"
        lib/L_System/src/Production.cpp
        lib/L_System/include/Production.h
        lib/L_System/src/Validation.cpp
        lib/L_System/include/Validation.h
        lib/L_System/src/LSystemInterpreter.cpp
        lib/L_System/include/LSystemInterpreter.h
        test/L_System/U_Production.cpp test/L_System/U_Validation.cpp)

target_include_directories(TestSuite PUBLIC
        "include/"
        )


target_link_libraries(TestSuite PUBLIC lSystemLib)
target_link_libraries(main PUBLIC lSystemLib)