#ifndef GERENCIAMENTOVOO_HPP
#define GERENCIAMENTOVOO_HPP

#include <unordered_map>
#include "astronauta.hpp"
#include "voo.hpp"

using namespace std;

class GerenciamentoVoo {
 
    private:
        list<Voo*> voos;
        unordered_map<string, Astronauta*> astronautas;

    public:
        void cadastrarAstronauta(string cpf, string nome, int idade);
    
        void cadastrarVoo(int codigoVoo);
    
        void adicionarAstronautaEmVoo(string cpf, int codigoVoo);
    
        void removerAstronautaDeVoo(string cpf, int codigoVoo);
    
        void listarVoos();
};

#endif