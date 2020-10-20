//
// Created by user on 19/10/2020.
//

#ifndef JUEGO_CROCKITS_ESCENARIO_H
#define JUEGO_CROCKITS_ESCENARIO_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

class Escenario{
private:
    Sprite sp_escenario;
    Texture tex_escenario;
public:
    Escenario(Texture &texture);
    void actualizarEscenario(Texture &nueva_tex);
    void dibujar(RenderWindow &window);
};

#endif //JUEGO_CROCKITS_ESCENARIO_H
