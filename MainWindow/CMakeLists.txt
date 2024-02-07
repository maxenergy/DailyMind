# This CMakeLists file handles the compilation of the MainWindow module

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets REQUIRED)

# Add source files
set(SOURCE_FILES
    mainwindow.ui
    mainwindow.cpp
    textprocessor.cpp
)

# Add header files
set(HEADER_FILES
    mainwindow.h
    textprocessor.h
)

# Tell CMake to create the executable
add_library(MainWindow ${SOURCE_FILES} ${HEADER_FILES})

# Use the Widgets module from Qt 5
target_link_libraries(MainWindow Qt5::Widgets)
