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
add_executable(main
        "src/main.cpp"
        )

target_include_directories(main PUBLIC
        "include/"
        )

add_executable(TestSuite
        "test/main.cpp"
        )

target_include_directories(TestSuite PUBLIC
        "include/"
        )

#target_link_libraries(TestSuite PUBLIC DataStructure)