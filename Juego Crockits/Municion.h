//
// Created by user on 20/10/2020.
//

#ifndef JUEGO_CROCKITS_MUNICIONES_H
#define JUEGO_CROCKITS_MUNICIONES_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class Municion {
private:
    float x;
    float y;
    Sprite sp_municion;
public:
    Municion();
    void generarPosicionAleatorio();
};


#endif //JUEGO_CROCKITS_MUNICIONES_H
