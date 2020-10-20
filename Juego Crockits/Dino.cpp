//
// Created by user on 19/10/2020.
//

#include "Dino.h"
using namespace sf;

Dino::Dino(float x_inicial, float y_inicial, Texture &texture, int a_inicial, int b_inicial){
    x = x_inicial;
    y = y_inicial;
    sp_Dino.setTexture(texture);
    a = a_inicial;
    b = b_inicial;
}

void Dino::mover(float x, float y, RenderWindow &window) {
    this->x += x;
    this->y += y;

    if(this->x > 724){
        this->x = 724;
    }

    if (this->x < 300){
        this->x = 300;
    }

    if(this->y < 180){
        this->y = 180;
    }

    if(this->y > 450){
        this->y = 450;
    }

}

int Dino::getX() {
    return this->x;
}


void Dino::set_a(int valor_a){
    this->a += valor_a;
    if(this->a >= 11){
        this->a = 0;
    }
}

void Dino::set_b(int valor_b){
    this->b = valor_b;
}

void Dino::dibujar(RenderWindow &window, int orientacion, int cantIzq, int cantDer) {

    if(cantIzq > cantDer){
        if(cantIzq == 1){
            this->a = 0;
        }
        sp_Dino.setScale(-1,1);
    }

    if(cantDer > cantIzq){
        if(cantDer == 1){
            this->a = 0;
        }
        sp_Dino.setScale(1,1);
    }

    sp_Dino.setPosition(this->x,this->y);
    sp_Dino.setTextureRect({(this->a*72),(this->b*72), 72, 72});
    window.draw(sp_Dino);
}
