//
// Created by user on 19/10/2020.
//

#include "Escenario.h"
using namespace sf;

Escenario::Escenario(Texture &texture){
    sp_escenario.setTexture(texture);
}

void Escenario::actualizarEscenario(Texture &nueva_tex) {
    this->tex_escenario = nueva_tex;
    sp_escenario.setTexture(tex_escenario);
}

void Escenario::dibujar(RenderWindow &window){
    window.draw(sp_escenario);
}