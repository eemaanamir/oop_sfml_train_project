cmake_minimum_required(VERSION 3.16)
project(sfml1)

set(CMAKE_CXX_STANDARD 14)



# Detect and add SFML
#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${/usr/share/SFML/cmake/Modules/FindSFML.cmake})
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics)
add_executable(sfml1 main.cpp)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(sfml1 ${SFML_LIBRARIES})
endif()

