cmake_minimum_required(VERSION 3.17)
project(Juego_Crockits)

set(CMAKE_CXX_STANDARD 14)

add_executable(Juego_Crockits main.cpp Dino.cpp Dino.h Escenario.cpp Escenario.h Crockit.cpp Crockit.h Node.h LinkedList.h Municion.cpp Municion.h)

target_link_libraries(Juego_Crockits sfml-system sfml-window sfml-graphics sfml-audio)
