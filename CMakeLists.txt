cmake_minimum_required(VERSION 3.14)

# Set the project name and version
project(PersonalDiaryApp VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the Qt5 package
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Include current directory for the UI files
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Set the CMake AUTOMOC and AUTOUIC options
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Add subdirectories
add_subdirectory(MainWindow)
add_subdirectory(Screenshot)
add_subdirectory(BrowsingHistory)
add_subdirectory(SpeechRecognition)
add_subdirectory(DataStorage)

# Add the executable
add_executable(${PROJECT_NAME} main.cpp)

# Link the Qt5 Widgets library
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

# Set the Vcpkg toolchain file
set(CMAKE_TOOLCHAIN_FILE "D:/source/common/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")