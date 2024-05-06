#ifndef FUNCOES_MENU_HPP
#define FUNCOES_MENU_HPP

#include "astronauta.hpp"
#include "voo.hpp"
#include "gerenciamentoVoo.hpp"

using namespace std;

void cadastrarAstronautas(list<Astronauta> &astronautas);

void cadastrarVoos(list<Voo> &voos);

void adicionarAtronautaVoo(list<Voo> &voos, list<Astronauta> &astronautas, multimap<int, Astronauta> &passageiros, GerenciamentoVoo gerenciamentoVoo);

void removerAstronautaVoo(list<Voo> &voos, list<Astronauta> &astronautas, multimap<int, Astronauta> &passageiros, GerenciamentoVoo gerenciamentoVoo);

void lancarVoo(list<Voo> &voos, list<Astronauta> &astronautas, multimap<int, Astronauta> &passageiros, GerenciamentoVoo gerenciamentoVoo);

void explodirVoo(list<Voo> &voos, list<Astronauta> &astronautas, multimap<int, Astronauta> &passageiros, GerenciamentoVoo gerenciamentoVoo);

void finalizarVoo(list<Voo> &voos, list<Astronauta> &astronautas, multimap<int, Astronauta> &passageiros, GerenciamentoVoo gerenciamentoVoo);

void listarVoo(list<Voo> &voos, multimap<int, Astronauta> &passageiros);

void listarAstronautasMortos(list<Astronauta> &astronautas);

#endif