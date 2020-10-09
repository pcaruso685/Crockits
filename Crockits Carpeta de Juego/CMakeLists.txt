cmake_minimum_required(VERSION 3.17)
project(Crockits_Carpeta_de_Juego)

set(CMAKE_CXX_STANDARD 14)

add_executable(Crockits_Carpeta_de_Juego main.cpp Pac.h Escenario.h)

target_link_libraries(Crockits_Carpeta_de_Juego sfml-system sfml-window sfml-graphics sfml-audio)