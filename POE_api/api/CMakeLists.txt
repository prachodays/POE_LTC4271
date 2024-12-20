# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set project name
project(main)

# Set the C standard
set(CMAKE_C_STANDARD 99)

# Add the directory containing LTC4271.h to the include path
include_directories(${CMAKE_SOURCE_DIR}/hdr)  # Adjust the path as necessary
include_directories(${CMAKE_SOURCE_DIR}/src) 
# Set container explorer sources
file(GLOB SRC
    src/*.c  # Collect all C source files in the src directory
    hdr/*.c
    hdr/*.h
)

# Set executable name and sources for container explorer
add_executable("${PROJECT_NAME}"
    ${SRC}
)
# Find and link the I2C library
find_library(I2C_LIB i2c)
if(I2C_LIB)
    target_link_libraries("${PROJECT_NAME}" ${I2C_LIB})
else()
    message(WARNING "I2C library not found. Please ensure it is installed.")
endif()
