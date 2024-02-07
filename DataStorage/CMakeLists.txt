# This CMakeLists file handles the compilation of the Data Storage module

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Add source files
set(SOURCE_FILES
    datastore.cpp
)

# Add header files
set(HEADER_FILES
    datastore.h
)

# Tell CMake to create the executable
add_library(DataStorage ${SOURCE_FILES} ${HEADER_FILES})
