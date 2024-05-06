#include "../header/funcoesMenu.hpp"
#include <iostream>
//#include <unistd.h>

using namespace std;

void cadastrarAstronautas(list<Astronauta> &astronautas){
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

    astronautas.push_back(Astronauta(cpf, nome, idade));
    cout << "Astronauta cadastrado com sucesso." << endl;

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
        cadastrarAstronautas(astronautas);
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        //sleep(2);
        system("clear");
        return;
    }
}
    
void cadastrarVoos(list<Voo> &voos){
    system("clear");
    int codigoVoo;
    int choice;

    cout << "Informe o código do voo a ser planejado: ";
    cin >> codigoVoo;

    voos.push_back(Voo(codigoVoo));
    cout << "Voo cadastrado com sucesso." << endl;

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
        cadastrarVoos(voos);
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        //sleep(2);
        system("clear");
        return;
    }
}

void adicionarAtronautaVoo(list<Voo> &voos, list<Astronauta> &astronautas, multimap<int, Astronauta> &passageiros, GerenciamentoVoo gerenciamentoVoo){
    system("clear");
    string cpf;
    int codigoVoo;
    int choice;

    cout << "Informe o cpf do astrounauta que deseja adicionar em algum voo: ";
    cin >> cpf;
    cout << "Informe o código do voo que o astronauta será adicionado: ";
    cin >> codigoVoo;

    for (auto ita = astronautas.begin(); ita != astronautas.end(); ita++) {
        if (ita->getCpf() == cpf) {
            for (auto it = voos.begin(); it != voos.end(); it++) {
                if ((it)->getCodigo() == codigoVoo) {
                    gerenciamentoVoo.adicionarAstronautaEmVoo(codigoVoo, (*ita), passageiros);
                }
            }
        }
    }
    
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
        adicionarAtronautaVoo(voos, astronautas, passageiros, gerenciamentoVoo);
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        //sleep(2);
        system("clear");
        return;
    }
    
}

void removerAstronautaVoo(list<Voo> &voos, list<Astronauta> &astronautas, multimap<int, Astronauta> &passageiros, GerenciamentoVoo gerenciamentoVoo){
    system("clear");
    string cpf;
    int codigoVoo;
    int choice;
    bool verifica = false;
    list<Voo>::iterator it;

    cout << "Informe o código do voo que terá o(s) astronauta(s) removido(s): ";
    cin >> codigoVoo;

    for (it = voos.begin(); it != voos.end(); ++it) {
        if ((it)->getCodigo() == codigoVoo) {
            verifica = true;
        }
    }

    if (verifica) {
        verifica = false;
    } else {
        cout << "Voo não encontrado" << endl;
        //sleep(2);
        system("clear");
        removerAstronautaVoo(voos, astronautas, passageiros, gerenciamentoVoo);
    }

    do {   
        cout << "Informe o cpf do astronauta a ser removido: ";
        cin >> cpf;

        for (auto ita = astronautas.begin(); ita != astronautas.end(); ++ita) {
            if ((ita)->getCpf() == cpf) {
                gerenciamentoVoo.removerAstronautaDeVoo(codigoVoo, (*ita), verifica, passageiros);
            }
        }

        do {
            cout << "Deseja remover outro astronauta desse voo" << endl;
            cout << "1 - sim | 2 - não" << endl;
            cin >> choice;
        } while ((choice != 1) && (choice != 2));
    } while (choice != 2);
    
    system("clear");
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
        removerAstronautaVoo(voos, astronautas, passageiros, gerenciamentoVoo);
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        //sleep(2);
        system("clear");
        return;
    }
}

void lancarVoo(list<Voo> &voos, list<Astronauta> &astronautas, multimap<int, Astronauta> &passageiros, GerenciamentoVoo gerenciamentoVoo){
    system("clear");
    int codigoVoo;
    int choice;
    bool verifica = false;

    cout << "Informe o código do voo que deseja lançar: ";
    cin >> codigoVoo;

    for (auto it = voos.begin(); it != voos.end(); ++it) {
        if ((it)->getCodigo() == codigoVoo) {
            verifica = true;
            gerenciamentoVoo.lancarVoo((*it), astronautas, passageiros);
        }
    }

    if (!verifica) {
        cout << "Voo não encontrado" << endl;
        //sleep(2);
        system("clear");
        lancarVoo(voos, astronautas, passageiros, gerenciamentoVoo);
    }
    
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
        lancarVoo(voos, astronautas, passageiros, gerenciamentoVoo);
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        //sleep(2);
        system("clear");
        return;
    }
}

void explodirVoo(list<Voo> &voos, list<Astronauta> &astronautas, multimap<int, Astronauta> &passageiros, GerenciamentoVoo gerenciamentoVoo){
    system("clear");
    int codigoVoo;
    int choice;
    bool verifica = false;

    cout << "Informe o código do voo que deseja explodir: ";
    cin >> codigoVoo;

    for (auto it = voos.begin(); it != voos.end(); ++it) {
        if ((it)->getCodigo() == codigoVoo) {
            verifica = true;
            gerenciamentoVoo.explodirVoo((*it), astronautas, passageiros);
            break;
        }
    }

    if (!verifica) {
        cout << "Voo não encontrado" << endl;
        //sleep(2);
        system("clear");
        explodirVoo(voos, astronautas, passageiros, gerenciamentoVoo);
    }
    
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
        explodirVoo(voos, astronautas, passageiros, gerenciamentoVoo);
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        //sleep(2);
        system("clear");
        return;
    }
}

void finalizarVoo(list<Voo> &voos, list<Astronauta> &astronautas, multimap<int, Astronauta> &passageiros, GerenciamentoVoo gerenciamentoVoo){
    system("clear");
    int codigoVoo;
    int choice;
    bool verifica = false;

    cout << "Informe o código do voo que deseja finalizar: ";
    cin >> codigoVoo;

    for (auto it = voos.begin(); it != voos.end(); ++it) {
        if ((it)->getCodigo() == codigoVoo) {
            verifica = true;
            gerenciamentoVoo.finalizarVoo((*it), astronautas, passageiros);
        }
    }

    if (!verifica) {
        cout << "Voo não encontrado" << endl;
        //sleep(2);
        system("clear");
        finalizarVoo(voos, astronautas, passageiros, gerenciamentoVoo);
    }
    
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
        finalizarVoo(voos, astronautas, passageiros, gerenciamentoVoo);
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        //sleep(2);
        system("clear");
        return;
    }
}

void listarVoo(list<Voo> &voos, multimap<int, Astronauta> &passageiros) {
    system("clear");
    cout << "=== Voos em planejamento ===" << endl;
    for (auto it = voos.begin(); it != voos.end(); ++it) {
        cout << "   Voo: " << it->getCodigo() << endl;
        if (it->getStatus() == 'p') {
            cout << "   Astronautas no voo:" << endl;    
            for (auto itp = passageiros.find(it->getCodigo()); itp != passageiros.upper_bound(it->getCodigo()); ++itp) {
                cout << "       Nome: " << itp->second.getNome() << ", Cpf: " << itp->second.getCpf() << ", Idade: " << itp->second.getIdade() << endl;
            }
        } 
    }

    cout << "=== Voos em curso ===" << endl;
    for (auto it = voos.begin(); it != voos.end(); ++it) {
        cout << "   Voo: " << it->getCodigo() << endl;
        if (it->getStatus() == 'c') {
            cout << "   Astronautas no voo:" << endl;    
            for (auto itp = passageiros.find(it->getCodigo()); itp != passageiros.upper_bound(it->getCodigo()); ++itp) {
                cout << "       Nome: " << itp->second.getNome() << ", Cpf: " << itp->second.getCpf() << ", Idade: " << itp->second.getIdade() << endl;
            }
        } 
    }

    cout << "=== Voos finalizados sem sucesso ===" << endl;
    for (auto it = voos.begin(); it != voos.end(); ++it) {
        cout << "   Voo: " << it->getCodigo() << endl;
        if (it->getStatus() == 'e') {
            cout << "   Astronautas no voo:" << endl;    
            for (auto itp = passageiros.find(it->getCodigo()); itp != passageiros.upper_bound(it->getCodigo()); ++itp) {
                cout << "       Nome: " << itp->second.getNome() << ", Cpf: " << itp->second.getCpf() << ", Idade: " << itp->second.getIdade() << endl;
            }
        } 
    }

    cout << "=== Voos finalizados com sucesso ===" << endl;
    for (auto it = voos.begin(); it != voos.end(); ++it) {
        cout << "   Voo: " << it->getCodigo() << endl;
        if (it->getStatus() == 'f') {
            cout << "   Astronautas no voo:" << endl;    
            for (auto itp = passageiros.find(it->getCodigo()); itp != passageiros.upper_bound(it->getCodigo()); ++itp) {
                cout << "       Nome: " << itp->second.getNome() << ", Cpf: " << itp->second.getCpf() << ", Idade: " << itp->second.getIdade() << endl;
            }
        } 
    }
}

void listarAstronautasMortos(list<Astronauta> &astronautas){
    system("clear");
    cout << "=== Astronautas Mortos ===" << endl;
    
    for (auto it = astronautas.begin(); it != astronautas.end(); ++it) {
        if (it->getVivo() == false) {
            cout << "Nome: " << it->getNome() << ", CPF: " << it->getCpf() << endl;
            list<int> voos = it->getHistorico();
            cout << "Voos que participou: ";
            for (auto itv = voos.begin(); itv != voos.end(); ++itv) {
                if(itv == voos.end()){
                    cout << (*itv) << "";
                } else {
                    cout << (*itv) << ", ";
                }
            }
        }
    }
}