#ifndef FUNCOES_MENU_HPP
#define FUNCOES_MENU_HPP

#include "astronauta.hpp"
#include "voo.hpp"
#include "gerenciamentoVoo.hpp"
 
using namespace std;

void cadastrarAstronautas(GerenciamentoVoo gerenciamentoVoo);

void cadastrarVoos(GerenciamentoVoo gerenciamentoVoo);

void adicionarAtronautaVoo(GerenciamentoVoo gerenciamentoVoo);

// void removerAstronautaVoo(unordered_map<string, Astronauta*> astronautas, list<Voo*> voos);

// void lancarVoo(list<Voo*> voos);

// void explodirVoo(list<Voo*> voos);

// void finalizarVoo(unordered_map<string, Astronauta*> astronautas, list<Voo*> voos);

// void listarVoo(unordered_map<string, Astronauta*>, list<Voo*> voos);

// void listarAstronautasMortos(unordered_map<string, Astronauta*> astronautas);

#endif