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