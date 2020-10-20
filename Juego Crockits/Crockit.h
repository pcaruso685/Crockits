//
// Created by user on 20/10/2020.
//

#ifndef JUEGO_CROCKITS_CROCKITS_H
#define JUEGO_CROCKITS_CROCKITS_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

class Crockit {
    private:
        float x;
        float y;
        Sprite sp_Crockit;
    public:
        Crockit(float x_inicial, float y_inicial, Texture &texture);
        Crockit();
    void dibujar(RenderWindow &window, int orientacion);
};


#endif //JUEGO_CROCKITS_CROCKITS_H
