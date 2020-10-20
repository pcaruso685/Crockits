//
// Created by user on 20/10/2020.
//

#include "Crockit.h"

Crockit::Crockit(float x_inicial, float y_inicial, Texture &texture) {
    this->x = x_inicial;
    this->y = y_inicial;
    sp_Crockit.setTexture(texture);
    sp_Crockit.setScale(0.250,0.250);
}

Crockit::Crockit(){

}

void Crockit::dibujar(RenderWindow &window, int orientacion) {
    if(orientacion == 1)
        sp_Crockit.setScale(-0.250,0.250);
    sp_Crockit.setPosition(this->x,this->y);
    window.draw(sp_Crockit);
}
