#ifndef GERENCIAMENTOVOO_HPP
#define GERENCIAMENTOVOO_HPP

#include <map>
#include "astronauta.hpp"
#include "voo.hpp"

using namespace std;

class GerenciamentoVoo {
    private:
        //map<int, Astronauta> passageiros;
        //unordered_map<string, Astronauta> astronautas;

    public:
        //void cadastrarAstronauta(string cpf, string nome, int idade);
    
        //void cadastrarVoo(int codigoVoo);
    
        void adicionarAstronautaEmVoo(int codigoVoo, Astronauta &astronauta, multimap<int, Astronauta> &passageiros);
    
        void removerAstronautaDeVoo(int codigoVoo, Astronauta &astronauta, bool verifica, multimap<int, Astronauta> &passageiros);

        void lancarVoo(Voo &voo, list<Astronauta> &astronautas, multimap<int, Astronauta> &passageiros);

        void explodirVoo(Voo &voo, list<Astronauta> &astronautas, multimap<int, Astronauta> &passageiros);

        void finalizarVoo(Voo &voo, list<Astronauta> &astronautas, multimap<int, Astronauta> &passageiros);
};

#endif