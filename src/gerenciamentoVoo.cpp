#include "../header/gerenciamentoVoo.hpp"
#include <iostream>

// void GerenciamentoVoo::cadastrarAstronauta(string cpf, string nome, int idade) {
//     if (astronautas.find(cpf) == astronautas.end()) {
//         astronautas[cpf] = Astronauta(cpf, nome, idade);
//         cout << "Astronauta cadastrado com sucesso." << endl;
//         //return;
//     } else {
//         cout << "Astronauta já cadastrado." << endl;
//         //return;
//     }
// }

// void GerenciamentoVoo::cadastrarVoo(int codigoVoo) {
//     voos.push_back(Voo(codigoVoo));
//     cout << "Voo cadastrado com sucesso." << endl;
//     cout << voos.size();
// }

void GerenciamentoVoo::adicionarAstronautaEmVoo(int codigoVoo, Astronauta astronauta) {
    passageiros.insert(make_pair(astronauta, codigoVoo));
    cout << "O astronauta " << astronauta.getNome() << "foi adiconado no voo " << codigoVoo;
}

// void GerenciamentoVoo::removerAstronautaDeVoo(int codigoVoo, Astronauta astronauta, bool verifica) {
//     for (auto it = passageiros.begin(); it != passageiros.end(); ++it) {
//         if (((it)->second == codigoVoo)) {
//             verifica = true;
//             passageiros.erase(astronauta);
//         }
//     }
// }

//void GerenciamentoVoo::lancarVoo(list<Voo> &voos, unordered_map<string, Astronauta> &astronautas){

//}

// void GerenciamentoVoo::listarVoos() {
//     for (Voo* voo : voos) {
//         cout << "Código do Voo: " << voo->getCodigo() << endl;
//         cout << "Passageiros: ";
//         for (Astronauta* astronauta : voo->getPassageiros()) {
//             cout << astronauta->getNome() << " ";
//         }
//         cout << endl;
//     }
// }