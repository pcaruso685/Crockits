#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include "Dino.h"
#include "Escenario.h"
using namespace std;
using namespace sf;

#define MOV_POS 10
#define MOV_NEG -10

void cargar_puntuaciones(int);
void leer_puntuaciones();

int main() {
    RenderWindow window(VideoMode(1024,766), "Crockits", Style::Close);
    window.setFramerateLimit(60);
    Texture tex_dino;
    Texture tex_escenario;
    Texture tex_escenario2;
    Texture tex_escenario3;
    int contador_escenario = 0;
    int contador_movimientos = 0;
    //int contador_segundos = 0;

    tex_dino.setSmooth(true);

    if(!tex_dino.loadFromFile("dino.png")){
        EXIT_FAILURE;
    }

    if(!tex_escenario.loadFromFile("escenario1.png")){
        EXIT_FAILURE;
    }

    if(!tex_escenario2.loadFromFile("escenario2.png")){
        EXIT_FAILURE;
    }

    if(!tex_escenario3.loadFromFile("escenario3.png")){
        EXIT_FAILURE;
    }

    Dino dino(window.getSize().x/2,window.getSize().y/2,tex_dino,0,0);
    Escenario escenario(tex_escenario);

    while(window.isOpen()){

        Event event;

        while(window.pollEvent(event)){
            switch(event.type){
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    ++contador_movimientos;
            }

            if(Keyboard::isKeyPressed(Keyboard::Left)){
                dino.mover(MOV_NEG,0,window);
                dino.set_a(0);
                dino.set_b(0);
            }
            if(Keyboard::isKeyPressed(Keyboard::Right)){
                dino.mover(MOV_POS,0,window);
                dino.set_b(0);
            }
            if(Keyboard::isKeyPressed(Keyboard::Up)){
                dino.mover(0,MOV_NEG,window);
            }
            if(Keyboard::isKeyPressed(Keyboard::Down)){
                dino.mover(0,MOV_POS,window);
            }
            if(Keyboard::isKeyPressed((Keyboard::Space))){
                ++contador_escenario;
                switch(contador_escenario){
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
        dino.dibujar(window);
        //pacwoman.dibujar(window);
        window.display();

    }
    cargar_puntuaciones(contador_movimientos);
    leer_puntuaciones();
    cout<<endl<<endl;
    system("pause");
    return 0;
}

void cargar_puntuaciones(int cantidad_movimientos){
    ofstream archivo;
    archivo.open("Puntuaciones.txt");
    if(archivo.is_open()){

        if(cantidad_movimientos <= 25)
            archivo<<"Lo siento, solo has realizado 25 o menos movimientos."<<endl;
        if(cantidad_movimientos > 50 || cantidad_movimientos <= 100)
            archivo<<"Genial!, has logrado hacer entre 50 y 100 movimientos!"<<endl;
        if(cantidad_movimientos > 100)
            archivo<<"Excelente!, has jugado mas de 100 movimientos!"<<endl;

        archivo<<"Cantidad de Movimientos: "<<cantidad_movimientos;

    }else{
        cout<<"El archivo no se pudo abrir correctamente"<<endl;
    }
    archivo.close();
}

void leer_puntuaciones(){
    ifstream archivo;
    string mensaje = " ";
    archivo.open(("Puntuaciones.txt"));
    if(archivo.is_open()){
        while(!archivo.eof()){
            getline(archivo,mensaje,'\n');
            cout<<mensaje<<endl;
        }
    }else{
        cout<<"El archivo no se pudo abrir correctamente"<<endl;
    }
    archivo.close();
}
