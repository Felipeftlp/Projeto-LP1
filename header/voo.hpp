#ifndef VOO_HPP
#define VOO_HPP

#include "astronauta.hpp"
#include <list>

using namespace std;

class Voo {
    private:
        int codigoVoo;
        char status;
        // p - planejamento
        // c - em curso
        // f - finalizado
        // e - explodiu

    public:
        Voo(int codigoVoo);
        
        int getCodigo();

        char getStatus();

        //list<Astronauta> getPassageiros();

        void setCodigo(int codigoVoo);

        void setStatus(char novo_status);
    
        //void adicionarAstronauta(Astronauta astronautas);

        // void removerAstronauta(string cpf);

        // void lancarVoo(list<Astronauta*> astronautas);

        // void explodirVoo();

        // void finalizarVoo(list<Astronauta*> astronautas);
    };

#endif