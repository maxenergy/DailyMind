# This CMakeLists file handles the compilation of the Speech Recognition module

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

# Add source files
set(SOURCE_FILES
    speechrecognizer.cpp
)

# Add header files
set(HEADER_FILES
    speechrecognizer.h
)

# Tell CMake to create the executable
add_library(SpeechRecognition ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(SpeechRecognition Qt5::Widgets)
