//
// Created by user on 19/10/2020.
//

#ifndef JUEGO_CROCKITS_DINO_H
#define JUEGO_CROCKITS_DINO_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

class Dino{
private :
    float x;
    float y;
    Sprite sp_Dino;
    int a;
    int b;
public:
    Dino(float x_inicial, float y_inicial, Texture &texture, int a_inicial, int b_inicial);
    void mover(float x, float y, RenderWindow &window);
    int getX();
    void set_a(int valor_a);
    void set_b(int valor_b);
    void dibujar(RenderWindow &window,int orientacion,int cantIzq, int cantDer);
};

#endif //JUEGO_CROCKITS_DINO_H
