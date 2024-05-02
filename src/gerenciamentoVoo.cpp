#include "../header/gerenciamentoVoo.hpp"
#include <iostream>

void GerenciamentoVoo::cadastrarAstronauta(string cpf, string nome, int idade) {
    if (astronautas.find(cpf) == astronautas.end()) {
        Astronauta* novoAstronauta = new Astronauta(cpf, nome, idade);
        astronautas[cpf] = novoAstronauta;
        cout << "Astronauta cadastrado com sucesso." << endl;
        //return;
    } else {
        cout << "Astronauta já cadastrado." << endl;
        //return;
    }
}

void GerenciamentoVoo::cadastrarVoo(int codigoVoo) {
    Voo* novoVoo = new Voo(codigoVoo);
    voos.push_back(novoVoo);
    cout << "Voo cadastrado com sucesso." << endl;
}

void GerenciamentoVoo::adicionarAstronautaEmVoo(string cpf, int codigoVoo) {
    if (astronautas.find(cpf) != astronautas.end()) {
        for (auto it = voos.begin(); it != voos.end(); ++it) {
            if ((*it)->getCodigo() == codigoVoo) {
                (*it)->adicionarAstronauta(astronautas[cpf]);
                return;
            }
        }
        cout << "Voo não encontrado." << endl;
    } else {
        cout << "Astronauta não encontrado." << endl;
    }
}

void GerenciamentoVoo::removerAstronautaDeVoo(string cpf, int codigoVoo) {
    for (auto it = voos.begin(); it != voos.end(); ++it) {
        if ((*it)->getCodigo() == codigoVoo) {
            (*it)->removerAstronauta(cpf);
            return;
        }
    }
    cout << "Voo não encontrado." << endl;
}

void GerenciamentoVoo::listarVoos() {
    for (Voo* voo : voos) {
        cout << "Código do Voo: " << voo->getCodigo() << endl;
        cout << "Passageiros: ";
        for (Astronauta* astronauta : voo->getPassageiros()) {
            cout << astronauta->getNome() << " ";
        }
        cout << endl;
    }
}