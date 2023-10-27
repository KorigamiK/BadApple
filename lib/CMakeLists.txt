cmake_minimum_required(VERSION 3.14.0)

set(LOCAL_PROJECT_NAME        "BadApple")
set(LOCAL_PROJECT_VERSION     "0.0.2")
set(LOCAL_PROJECT_DESCRIPTION "Description")

project(
  ${LOCAL_PROJECT_NAME}
  VERSION ${LOCAL_PROJECT_VERSION}
  DESCRIPTION ${LOCAL_PROJECT_DESCRIPTION}
  LANGUAGES CXX
)


set(CPACK_PROJECT_NAME ${LOCAL_PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${LOCAL_PROJECT_VERSION})

# Header files (relative to "include" directory)
set(HEADERS
    header.h
)

# Source files (relative to "src" directory)
set(SOURCES
    main.cpp
)

# Compiler definitions
set(DEFINES

)

# Compiler options
set(OPTIONS

)

list(TRANSFORM HEADERS PREPEND "include/")
list(TRANSFORM SOURCES PREPEND "src/")

SET(CMAKE_EXE_LINKER_FLAGS "-L/usr/local/lib")

add_executable(${LOCAL_PROJECT_NAME})

find_package(OpenCV CONFIG REQUIRED) 

target_include_directories(${LOCAL_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include 
  ${OpenCV_INCLUDE_DIRS}
)

target_sources(${LOCAL_PROJECT_NAME} PUBLIC ${SOURCES} ${HEADERS})

target_link_directories(${LOCAL_PROJECT_NAME} PUBLIC
  ${OpenCV_LIB_DIRS}
)

target_link_libraries(${LOCAL_PROJECT_NAME}
  ${OpenCV_LIBS}
)

target_compile_definitions(${LOCAL_PROJECT_NAME} PRIVATE ${DEFINES})
target_compile_options(${LOCAL_PROJECT_NAME} PRIVATE ${OPTIONS})

target_compile_definitions(${LOCAL_PROJECT_NAME} PRIVATE ${DEFINES})
target_compile_options(${LOCAL_PROJECT_NAME} PRIVATE ${OPTIONS})

message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

execute_process(
  COMMAND ${CMAKE_COMMAND} -E create_symlink
  ${CMAKE_CURRENT_SOURCE_DIR}/vid
  ${CMAKE_CURRENT_BINARY_DIR}/vid
)

include(CPack)
