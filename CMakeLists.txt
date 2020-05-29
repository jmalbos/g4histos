cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(MARIJA)

find_package(GSL    REQUIRED)
find_package(Geant4 REQUIRED)

include(${Geant4_USE_FILE})

add_executable(main main.cpp)
target_link_libraries(main ${Geant4_LIBRARIES} ${GSL_LIBRARIES})
