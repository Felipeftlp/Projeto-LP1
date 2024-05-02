#include "../header/funcoesMenu.hpp"
#include <iostream>
//#include <unistd.h>

using namespace std;

void cadastrarAstronautas(GerenciamentoVoo gerenciamentoVoo){
    system("clear");
    string cpf;
    string nome;
    int idade;
    int choice;
 
    cout << "Informe o cpf do astronauta que deseja cadastrar: ";
    cin >> cpf;
    cout << "Informe o nome do astronauta que deseja cadastrar: ";
    cin >> nome;
    cout << "Informe a idade do astronauta que deseja cadastrar: ";
    cin >> idade;

    gerenciamentoVoo.cadastrarAstronauta(cpf, nome, idade);

    cout << "Deseja retornar ao menu inicial?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Não" << endl;
    cout << "Escolha uma opção: ";
    cin >> choice;

    if (choice == 1) {
        system("clear");
        cout << "Voltando ao Menu Principal..." << endl;
        //sleep(2);
        system("clear");
        return;
    } else if (choice == 2){
        system("clear");
        cadastrarAstronautas(gerenciamentoVoo);
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        //sleep(2);
        system("clear");
        return;
    }
}
    
void cadastrarVoos(GerenciamentoVoo gerenciamentoVoo){
    system("clear");
    int codigoVoo;
    int choice;

    cout << "Informe o código do voo a ser planejado: ";
    cin >> codigoVoo;

    gerenciamentoVoo.cadastrarVoo(codigoVoo);

    cout << "Deseja retornar ao menu inicial?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Não" << endl;
    cout << "Escolha uma opção: ";
    cin >> choice;

    if (choice == 1) {
        system("clear");
        cout << "Voltando ao Menu Principal..." << endl;
        //sleep(2);
        system("clear");
        return;
    } else if (choice == 2){
        system("clear");
        cadastrarVoos(gerenciamentoVoo);
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        //sleep(2);
        system("clear");
        return;
    }
}

void adicionarAtronautaVoo(GerenciamentoVoo gerenciamentoVoo){
    system("clear");
    string cpf;
    int codigoVoo;
    int choice;

    cout << "Informe o cpf do astrounauta que deseja adicionar em algum voo: ";
    cin >> cpf;
    cout << "Informe o código do voo que o astronauta será adicionado: ";
    cin >> codigoVoo;

    gerenciamentoVoo.adicionarAstronautaEmVoo(cpf, codigoVoo);
    
    cout << "Deseja retornar ao menu inicial?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Não" << endl;
    cout << "Escolha uma opção: ";
    cin >> choice;

    if (choice == 1) {
        system("clear");
        cout << "Voltando ao Menu Principal..." << endl;
        //sleep(2);
        system("clear");
        return;
    } else if (choice == 2){
        system("clear");
        adicionarAtronautaVoo(gerenciamentoVoo);
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        //sleep(2);
        system("clear");
        return;
    }
    
}

// void removerAstronautaVoo(unordered_map<string, Astronauta*> astronautas, list<Voo*> voos){
//     system("clear");
//     string cpf;
//     int codigoVoo;
//     int choice;
//     bool verifica = false;
//     list<Astronauta*>::iterator ita;
//     list<Voo*>::iterator it;

//     cout << "Informe o código do voo que terá o(s) astronauta(s) removido(s): ";
//     cin >> codigoVoo;

//     for (it = voos.begin(); it != voos.end(); ++it) {
//         if ((*it)->getCodigo() == codigoVoo) {
//             verifica = true;
//         }
//     }

//     if (verifica) {
//         verifica = false;
//     } else {
//         cout << "Voo não encontrado" << endl;
//         //sleep(2);
//         system("clear");
//         removerAstronautaVoo(astronautas, voos);
//     }

//     do {   
//         cout << "Informe o cpf do astronauta a ser removido: ";
//         cin >> cpf;

//         for (ita = astronautas.begin(); ita != astronautas.end(); ++ita) {
//             if ((*ita)->getCpf() == cpf) {
//                 verifica = true;
//             }
//         }
        
//         if (verifica) {
//             (*it)->removerPassageiro(cpf);
//         } else {
//             cout << "Astronauta não encontrado" << endl;
//         }

//         do {
//             system("clear");
//             cout << "Deseja remover outro astronauta desse voo" << endl;
//             cout << "1 - sim | 2 - não" << endl;
//             cin >> choice;
//         } while ((choice != 1) && (choice != 2));
//     } while (choice != 2);
    
//     cout << "Deseja retornar ao menu inicial?" << endl;
//     cout << "1 - Sim" << endl;
//     cout << "2 - Não" << endl;
//     cout << "Escolha uma opção: ";
//     cin >> choice;

//     if (choice == 1) {
//         system("clear");
//         cout << "Voltando ao Menu Principal..." << endl;
//         //sleep(2);
//         system("clear");
//         return;
//     } else if (choice == 2){
//         system("clear");
//         removerAstronautaVoo(astronautas, voos);
//     } else {
//         cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
//         //sleep(2);
//         system("clear");
//         return;
//     }
// }

// void lancarVoo(list<Voo*> voos){
//     system("clear");
//     int codigoVoo;
//     int choice;
//     bool verifica = false;
//     list<Voo*>::iterator it;
//     list<Astronauta*> passageiros;

//     cout << "Informe o código do voo que deseja lançar: ";
//     cin >> codigoVoo;

//     for (it = voos.begin(); it != voos.end(); ++it) {
//         if ((*it)->getCodigo() == codigoVoo) {
//             verifica = true;
//         }
//     }

//     if (verifica) {
//         passageiros = (*it)->getPassageiros();
//         (*it)->lancarVoo(passageiros);
//     } else {
//         cout << "Voo não encontrado" << endl;
//         //sleep(2);
//         system("clear");
//         lancarVoo(voos);
//     }
    
//     cout << "Deseja retornar ao menu inicial?" << endl;
//     cout << "1 - Sim" << endl;
//     cout << "2 - Não" << endl;
//     cout << "Escolha uma opção: ";
//     cin >> choice;

//     if (choice == 1) {
//         system("clear");
//         cout << "Voltando ao Menu Principal..." << endl;
//         //sleep(2);
//         system("clear");
//         return;
//     } else if (choice == 2){
//         system("clear");
//         lancarVoo(voos);
//     } else {
//         cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
//         //sleep(2);
//         system("clear");
//         return;
//     }
// }

// void explodirVoo(list<Voo*> voos){
//     system("clear");
//     int codigoVoo;
//     int choice;
//     bool verifica = false;
//     list<Voo*>::iterator it;
// //    list<Astronauta*> passageiros;

//     cout << "Informe o código do voo que deseja explodir: ";
//     cin >> codigoVoo;

//     for (it = voos.begin(); it != voos.end(); ++it) {
//         if ((*it)->getCodigo() == codigoVoo) {
//             verifica = true;
//         }
//     }

//     if (verifica) {
// //        passageiros = (*it)->getPassageiros();
//         (*it)->explodirVoo();
//     } else {
//         cout << "Voo não encontrado" << endl;
//         //sleep(2);
//         system("clear");
//         explodirVoo(voos);
//     }
    
//     cout << "Deseja retornar ao menu inicial?" << endl;
//     cout << "1 - Sim" << endl;
//     cout << "2 - Não" << endl;
//     cout << "Escolha uma opção: ";
//     cin >> choice;

//     if (choice == 1) {
//         system("clear");
//         cout << "Voltando ao Menu Principal..." << endl;
//         //sleep(2);
//         system("clear");
//         return;
//     } else if (choice == 2){
//         system("clear");
//         explodirVoo(voos);
//     } else {
//         cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
//         //sleep(2);
//         system("clear");
//         return;
//     }
// }

// void finalizarVoo(unordered_map<string, Astronauta*> astronautas, list<Voo*> voos){
//     system("clear");
//     int codigoVoo;
//     int choice;
//     bool verifica = false;
//     list<Voo*>::iterator it;
//     list<Astronauta*> passageiros;

//     cout << "Informe o código do voo que deseja finalizar: ";
//     cin >> codigoVoo;

//     for (it = voos.begin(); it != voos.end(); ++it) {
//         if ((*it)->getCodigo() == codigoVoo) {
//             verifica = true;
//         }
//     }

//     if (verifica) {
//         passageiros = (*it)->getPassageiros();
//         (*it)->finalizarVoo(passageiros);
//     } else {
//         cout << "Voo não encontrado" << endl;
//         //sleep(2);
//         system("clear");
//         finalizarVoo(astronautas, voos);
//     }
    
//     cout << "Deseja retornar ao menu inicial?" << endl;
//     cout << "1 - Sim" << endl;
//     cout << "2 - Não" << endl;
//     cout << "Escolha uma opção: ";
//     cin >> choice;

//     if (choice == 1) {
//         system("clear");
//         cout << "Voltando ao Menu Principal..." << endl;
//         //sleep(2);
//         system("clear");
//         return;
//     } else if (choice == 2){
//         system("clear");
//         finalizarVoo(astronautas, voos);
//     } else {
//         cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
//         //sleep(2);
//         system("clear");
//         return;
//     }
// }

// void listarVoo(unordered_map<string, Astronauta*> astronautas, list<Voo*> voos){
//     system("clear");
//     for (Voo* voo : voos) {
//         cout << "Código do Voo: " << voo->getCodigo() << endl;
//         cout << "Passageiros: ";
//         for (Astronauta* astronauta : voo->getPassageiros()) {
//             cout << astronauta->getNome() << " ";
//         }
//         cout << endl;
//     }
// }

// void listarAstronautasMortos(unordered_map<string, Astronauta*> astronautas){
//     system("clear");
// }