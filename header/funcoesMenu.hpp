#ifndef FUNCOES_MENU_HPP
#define FUNCOES_MENU_HPP

#include <list>
#include <map>
#include "astronauta.hpp"
#include "voo.hpp"
//#include "gerenciamentoVoo.hpp"

using namespace std;

class FuncoesMenu {
    private:
        list<Astronauta> astronautas;
        list<Voo> voos;
        map<string, Astronauta> astronautasCPF;
        map<int, Voo> codigoVoos;
        multimap<int, Astronauta> passageirosVoo;

    public:
        FuncoesMenu();

        //Astronautas
        //Astronauta& acharAstronauta(const string& cpf);
        //bool astronautaExiste(string);
        void cadastrarAstronautas();
        void adicionarAtronautaVoo();
        void removerAstronautaVoo();
        void listarAstronautasMortos();

        //Voos
        //Voo& acharVoo(int codigoVoo);
        //bool vooExiste(int codigoVoo);
        void cadastrarVoos();
        void lancarVoo();
        void explodirVoo();
        void finalizarVoo();
        void listarVoo();

};

#endif