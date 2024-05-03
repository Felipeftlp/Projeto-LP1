#ifndef GERENCIAMENTOVOO_HPP
#define GERENCIAMENTOVOO_HPP

#include <unordered_map>
#include "astronauta.hpp"
#include "voo.hpp"

using namespace std;

class GerenciamentoVoo {
    private:
        unordered_map<Astronauta, int> passageiros;
        //unordered_map<string, Astronauta> astronautas;

    public:
        //void cadastrarAstronauta(string cpf, string nome, int idade);
    
        //void cadastrarVoo(int codigoVoo);
    
        void adicionarAstronautaEmVoo(int codigoVoo, Astronauta astronauta);
    
        //void removerAstronautaDeVoo(int codigoVoo, Astronauta astronauta, bool verifica);

        //void lancarVoo(list<Voo> &voos, unordered_map<string, Astronauta> &astronautas);
    
        //void listarVoos();
};

#endif