# This CMakeLists file handles the compilation of the Browsing History module

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Add source files
set(SOURCE_FILES
    historytracker.cpp
)

# Add header files
set(HEADER_FILES
    historytracker.h
)

# Tell CMake to create the executable
add_library(BrowsingHistory ${SOURCE_FILES} ${HEADER_FILES})
