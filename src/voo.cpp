#include "../header/voo.hpp"
#include <iostream>

Voo::Voo() {}

Voo::Voo(int codigoVoo){
    this->codigoVoo = codigoVoo;
    this->status = 'p';
}

int Voo::getCodigo(){
    return codigoVoo;
}

char Voo::getStatus(){
    return status;
}

// list<Astronauta> Voo::getPassageiros() { 
//     return passageiros; 
// }

void Voo::setCodigo(int codigoVoo){
    this->codigoVoo = codigoVoo;
}

void Voo::setStatus(char novo_status){
    if (novo_status == 'p' || novo_status == 'c' || novo_status == 'f' || novo_status == 'e'){
        this->status = novo_status;
    } else {
        std::cout << "Status de voo inválido." << endl;
    }
}

// void Voo::adicionarAstronauta(Astronauta astronauta) {
//     if ((getStatus() == 'p') && (astronauta.getVivo())) {
//         passageiros.push_back(astronauta);
//         cout << "O astronauta " << astronauta.getNome() 
//              << "foi adicionado ao voo " << getCodigo() 
//              << "com sucesso." << endl;
//     } else {
//         cout << "O voo não está em planejamento." << endl;
//     }
// }

// void Voo::removerAstronauta(string cpf) {
//     if (getStatus() == 'p') {
//         for (auto it = passageiros.begin(); it != passageiros.end(); ++it) {
//             if ((*it)->getCpf() == cpf) {
//                 passageiros.erase(it);
//                 cout << "O astronauta " << (*it)->getNome() 
//                      << "foi removido do voo " << getCodigo() 
//                      << "com sucesso." << endl;
//                 return;
//             }
//         }
//         cout << "Astronauta não encontrado no voo." << endl;
//     } else {
//         cout << "Não é possível remover passageiros durante o voo." << endl;
//     }
// }

// void Voo::lancarVoo(list<Astronauta*> astronautas) {
//     bool podeLancar = true;
//     if ((passageiros.size() > 0) && (getStatus() == 'p')) {
//         for (auto it = passageiros.begin(); it != passageiros.end(); ++it) {
//             if (!((*it)->getDisponibilidade())) {
//                 podeLancar = false;
//             }
//         }
//         if (podeLancar) {
//             cout << "Voo lançado com sucesso." << endl;
//             setStatus('c');
//             for (auto it = astronautas.begin(); it != astronautas.end(); ++it) {
//                 (*it)->setDisponibilidade(false);
//             }
//         } else {
//             cout << "Verifique a disponibilidade dos astronautas antes, ou remova algum(ns) deles do voo." << endl;
//         }
//     } else {
//         cout << "Não é possível lançar o voo." << endl;
//     }
// }

// void Voo::explodirVoo() {
//     if (getStatus() == 'c') {
//         for (Astronauta* astronautas : passageiros) {
//             cout << "Astronauta " << astronautas->getNome() << " morreu." << endl;
//             astronautas->setVivo(false);
//             astronautas->setDisponibilidade(false);
//         }
//         passageiros.clear();
//         setStatus('e');
//     }
// }

// void Voo::finalizarVoo(list<Astronauta*> astronautas) {
//     if (getStatus() == 'c') {
//         cout << "Voo finalizado com sucesso." << endl;
//         setStatus('f');
//         for (auto it = astronautas.begin(); it != astronautas.end(); ++it) {
//             (*it)->setDisponibilidade(true);
//         }
//     } else {
//         cout << "Verifique o status do voo antes de realizar essa ação." << endl;
//     }
// }