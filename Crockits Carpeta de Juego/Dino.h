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
        Dino(float x_inicial, float y_inicial, Texture &texture, int a_inicial, int b_inicial){
            x = x_inicial;
            y = y_inicial;
            sp_Dino.setTexture(texture);
            a = a_inicial;
            b = b_inicial;
        }
        void mover(float x, float y, RenderWindow &window);
        void set_a(int valor_a);
        void set_b(int valor_b);
        void dibujar(RenderWindow &window);
};

void Dino::mover(float x, float y, RenderWindow &window) {
    this->x += x;
    this->y += y;

    if (this->x >= (window.getSize().x-sp_Dino.getTexture()->getSize().x)) {
        x = window.getSize().x - sp_Dino.getTexture()->getSize().x;
    }

    if (this->x <= (sp_Dino.getTexture()->getSize().x)) {
        x = sp_Dino.getTexture()->getSize().x;
    }

    if (this->y >= (window.getSize().y - sp_Dino.getTexture()->getSize().y)) {
        y = (window.getSize().y) - sp_Dino.getTexture()->getSize().y;
    }

    if (this->y <= (sp_Dino.getTexture()->getSize().y)){
        y = sp_Dino.getTexture()->getSize().y;
    }
}

void Dino::set_a(int valor_a){
    this->a = valor_a;
}

void Dino::set_b(int valor_b){
    this->b = valor_b;
}

void Dino::dibujar(RenderWindow &window) {
    sp_Dino.setPosition(this->x,this->y);
    sp_Dino.setTextureRect({(0),(this->b*218), 72, 72});
    window.draw(sp_Dino);
}



