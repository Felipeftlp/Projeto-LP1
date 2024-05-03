#ifndef FUNCOES_MENU_HPP
#define FUNCOES_MENU_HPP

#include "astronauta.hpp"
#include "voo.hpp"
#include "gerenciamentoVoo.hpp"
 
using namespace std;

void cadastrarAstronautas(unordered_map<string, Astronauta> &astronautas);

void cadastrarVoos(list<Voo> &voos);

void adicionarAtronautaVoo(list<Voo> &voos, unordered_map<string, Astronauta> &astronautas);

//void removerAstronautaVoo(unordered_map<string, Astronauta> &astronautas, list<Voo> &voos);

// void lancarVoo(list<Voo*> voos);

// void explodirVoo(list<Voo*> voos);

// void finalizarVoo(unordered_map<string, Astronauta*> astronautas, list<Voo*> voos);

// void listarVoo(unordered_map<string, Astronauta*>, list<Voo*> voos);

// void listarAstronautasMortos(unordered_map<string, Astronauta*> astronautas);

#endif