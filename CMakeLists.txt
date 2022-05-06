cmake_minimum_required(VERSION 3.20.0)
project(SWE_PROJECT VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} 
    main.cpp
    Database/database.cpp
    Database/table.cpp
    UI/UI.cpp
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC Database/includes
    PUBLIC UI/includes
)

add_executable(Test
    Test.cpp
    Database/database.cpp
    Database/table.cpp
    UI/UI.cpp
    Tests/TableTests.cpp
    Tests/DatabaseTests.cpp
)

target_include_directories(Test
    PUBLIC Database/includes
    PUBLIC UI/includes
    PUBLIC Tests/includes
)