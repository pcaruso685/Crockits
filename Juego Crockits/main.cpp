#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include "Dino.h"
#include "Crockit.h"
#include "Escenario.h"
#include "LinkedList.h"

using namespace std;
using namespace sf;

#define MOV_POS 10
#define MOV_NEG -10

void cargar_puntuaciones(int);

void leer_puntuaciones();

int main() {
    RenderWindow window(VideoMode(1024, 766), "Crockits", Style::Close);
    window.setFramerateLimit(60);
    Texture tex_dino;
    Texture tex_Crockit1a;
    Texture tex_Crockit2a;
    Texture tex_escenario;
    Texture tex_escenario2;
    Texture tex_escenario3;
    int contador_escenario = 0;
    int contador_movimientos = 0;
    int orientacion = 0;
    int cantDer = 0;
    int cantIzq = 0;
    float enemigoTamanioX = 0;
    float enemigoTamanioY = 0;
    //int contador_segundos = 0;

    tex_dino.setSmooth(true);
    tex_Crockit1a.setSmooth(true);

    if (!tex_dino.loadFromFile("dino.png")) {
        EXIT_FAILURE;
    }

    if (!tex_Crockit1a.loadFromFile("Crockit 1a.png")) {
        EXIT_FAILURE;
    }

    if (!tex_Crockit2a.loadFromFile("Crockit 2a.png"));

    if (!tex_escenario.loadFromFile("escenario1.png")) {
        EXIT_FAILURE;
    }

    if (!tex_escenario2.loadFromFile("escenario2.png")) {
        EXIT_FAILURE;
    }

    if (!tex_escenario3.loadFromFile("escenario3.png")) {
        EXIT_FAILURE;
    }

    enemigoTamanioX = tex_Crockit1a.getSize().x / 4;
    enemigoTamanioY = tex_Crockit1a.getSize().y / 4;

    Crockit enemigo1(0, 0, tex_Crockit1a);

    Crockit enemigo2(window.getSize().x, 0, tex_Crockit2a);

    Crockit enemigo3(0, window.getSize().y - enemigoTamanioY - 40, tex_Crockit2a);

    Crockit enemigo4(window.getSize().x, window.getSize().y - enemigoTamanioY - 40, tex_Crockit1a);

    Dino dino(window.getSize().x / 2, window.getSize().y / 2, tex_dino, 0, 0);

    Escenario escenario(tex_escenario);

    while (window.isOpen()) {

        Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    ++contador_movimientos;
            }

            if (Keyboard::isKeyPressed(Keyboard::Up)) {
                dino.set_a(1);
                dino.set_b(0);
                dino.mover(0, MOV_NEG, window);
            }

            if (Keyboard::isKeyPressed(Keyboard::Down)) {
                dino.set_a(1);
                dino.set_b(1);
                dino.mover(0, MOV_POS, window);
            }

            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                dino.mover(MOV_POS, 0, window);
                dino.set_a(1);
                dino.set_b(2);
                orientacion = 1;
                ++cantDer;
                cantIzq = 0;
            }

            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                dino.mover(MOV_NEG, 0, window);
                dino.set_a(1);
                dino.set_b(3);
                orientacion = 0;
                ++cantIzq;
                cantDer = 0;
            }

            if (Keyboard::isKeyPressed((Keyboard::Space))) {
                ++contador_escenario;
                switch (contador_escenario) {
                    case 3:
                        escenario.actualizarEscenario(tex_escenario2);
                        break;
                    case 6:
                        escenario.actualizarEscenario(tex_escenario3);
                        break;
                    case 9:
                        escenario.actualizarEscenario(tex_escenario);
                        contador_escenario = 0;
                        break;
                }
            }
        }

        window.clear();
        escenario.dibujar(window);
        dino.dibujar(window, orientacion, cantIzq, cantDer);
        enemigo1.dibujar(window, 0);
        enemigo2.dibujar(window, 1);
        enemigo3.dibujar(window, 0);
        enemigo4.dibujar(window, 1);
        window.display();

    }
    cargar_puntuaciones(contador_movimientos);
    leer_puntuaciones();
    cout << endl << endl;
    system("pause");
    return 0;
}

void cargar_puntuaciones(int cantidad_movimientos) {
    ofstream archivo;
    archivo.open("Puntuaciones.txt");
    if (archivo.is_open()) {

        if (cantidad_movimientos <= 25)
            archivo << "Lo siento, solo has realizado 25 o menos movimientos." << endl;
        if (cantidad_movimientos > 50 || cantidad_movimientos <= 100)
            archivo << "Genial!, has logrado hacer entre 50 y 100 movimientos!" << endl;
        if (cantidad_movimientos > 100)
            archivo << "Excelente!, has jugado mas de 100 movimientos!" << endl;

        archivo << "Cantidad de Movimientos: " << cantidad_movimientos;

    } else {
        cout << "El archivo no se pudo abrir correctamente" << endl;
    }
    archivo.close();
}

void leer_puntuaciones() {
    ifstream archivo;
    string mensaje = " ";
    archivo.open(("Puntuaciones.txt"));
    if (archivo.is_open()) {
        while (!archivo.eof()) {
            getline(archivo, mensaje, '\n');
            cout << mensaje << endl;
        }
    } else {
        cout << "El archivo no se pudo abrir correctamente" << endl;
    }
    archivo.close();
}
