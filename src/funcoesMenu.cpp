#include "../header/funcoesMenu.hpp"
#include <cstdlib>
#include <map>
#include <iostream>
#include <unistd.h>

using namespace std;

FuncoesMenu::FuncoesMenu() {}

void FuncoesMenu::cadastrarAstronautas(){
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

    if (astronautasCPF.find(cpf) != astronautasCPF.end()) {
        cout << "Esse astronauta já foi cadastrado no sistema." << endl;
        sleep(2);
        system("clear");
        return;
    }

    Astronauta novoAstronauta(cpf, nome, idade);

    astronautas.push_back(novoAstronauta);
    astronautasCPF[cpf] = novoAstronauta;
    cout << "Astronauta cadastrado com sucesso." << endl;

    cout << "Deseja retornar ao menu inicial?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Não" << endl;
    cout << "Escolha uma opção: ";
    cin >> choice;

    if (choice == 1) {
        system("clear");
        cout << "Voltando ao Menu Principal..." << endl;
        sleep(2);
        system("clear");
        return;
    } else if (choice == 2){
        system("clear");
        cadastrarAstronautas();
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        sleep(2);
        system("clear");
        return;
    }
}
    
void FuncoesMenu::cadastrarVoos(){
    system("clear");
    int codigoVoo;
    int choice;

    cout << "Informe o código do voo a ser planejado: ";
    cin >> codigoVoo;

    if (codigoVoos.find(codigoVoo) != codigoVoos.end()) {
        cout << "Esse voo já foi cadastrado no sistema." << endl;
        sleep(2);
        system("clear");
        return;
    }
    
    Voo novoVoo(codigoVoo);

    voos.push_back(novoVoo);
    codigoVoos[codigoVoo] = novoVoo;
    cout << "Voo cadastrado com sucesso." << endl;

    cout << "Deseja retornar ao menu inicial?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Não" << endl;
    cout << "Escolha uma opção: ";
    cin >> choice;

    if (choice == 1) {
        system("clear");
        cout << "Voltando ao Menu Principal..." << endl;
        sleep(2);
        system("clear");
        return;
    } else if (choice == 2){
        system("clear");
        cadastrarVoos();
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        sleep(2);
        system("clear");
        return;
    }
}

void FuncoesMenu::adicionarAtronautaVoo(){
    system("clear");
    string cpf;
    int codigoVoo;
    int choice;

    cout << "Informe o código do voo que o astronauta será adicionado: ";
    cin >> codigoVoo;

    if (codigoVoos.find(codigoVoo) != codigoVoos.end()) {
        Voo& voo = codigoVoos[codigoVoo];

        if (voo.getStatus() != 'p') {
            cout << "Não é possível adicionar astronautas a esse voo, pois ele não está em planejamento." << endl;
            sleep(2);
            system("clear");
            return;
        }

        cout << "Informe o cpf do astrounauta que deseja adicionar neste voo: ";
        cin >> cpf;
        cout << "" << endl;

        if (astronautasCPF.find(cpf) != astronautasCPF.end()) {
            Astronauta& astronauta = astronautasCPF[cpf];

            if (!astronauta.getVivo()) {
                cout << "Não é possível adicionar esse astronauta em voo, pois ele está morto" << endl;
                sleep(2);
                system("clear");
                return;
            }
            
            passageirosVoo.insert(make_pair(codigoVoo, astronauta));
            cout << "O astronauta " << astronauta.getNome() << " foi adiconado no voo " << codigoVoo << endl;
        } else {
            cout << "O astronauta não foi encontrado." << endl;
            sleep(2);
            system("clear");
            return;
        }
    } else {
        cout << "O voo não foi encontrado." << endl;
        sleep(2);
        system("clear");
        return;
    }
    
    
    cout << "Deseja retornar ao menu inicial?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Não" << endl;
    cout << "Escolha uma opção: ";
    cin >> choice;

    if (choice == 1) {
        system("clear");
        cout << "Voltando ao Menu Principal..." << endl;
        sleep(2);
        system("clear");
        return;
    } else if (choice == 2){
        system("clear");
        adicionarAtronautaVoo();
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        sleep(2);
        system("clear");
        return;
    }
    
}

void FuncoesMenu::removerAstronautaVoo(){
    system("clear");
    string cpf;
    int codigoVoo;
    int choice;

    cout << "Informe o código do voo que terá o(s) astronauta(s) removido(s): ";
    cin >> codigoVoo;

    if (codigoVoos.find(codigoVoo) != codigoVoos.end()) {
        Voo& voo = codigoVoos[codigoVoo];

        if (voo.getStatus() != 'p') {
            cout << "Não é possível remover astronautas a esse voo, pois ele não está em planejamento." << endl;
            sleep(2);
            system("clear");
            return;
        }

        cout << "Informe o cpf do astrounauta que deseja adicionar neste voo: ";
        cin >> cpf;
        cout << "" << endl;

        if (astronautasCPF.find(cpf) != astronautasCPF.end()) {
            Astronauta& astronauta = astronautasCPF[cpf];

            if (!astronauta.getVivo()) {
                cout << "Não é possível remover esse astronauta em voo, pois ele está morto" << endl;
                sleep(2);
                system("clear");
                return;
            }
            
            auto it = passageirosVoo.find(codigoVoo);
    
            while (it != passageirosVoo.upper_bound(codigoVoo)) {
                if (it->second.getCpf() == astronauta.getCpf()) {
                    it = passageirosVoo.erase(it);
                } else {
                    ++it;
                }
            }
            
            cout << "O astronauta " << astronauta.getNome() << " foi removido do voo " << codigoVoo << endl;
        } else {
            cout << "O astronauta não foi encontrado." << endl;
            sleep(2);
            system("clear");
            return;
        }

    } else {
        cout << "O voo não foi encontrado." << endl;
        sleep(2);
        system("clear");
        return;
    }
    
    system("clear");
    cout << "Deseja retornar ao menu inicial?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Não" << endl;
    cout << "Escolha uma opção: ";
    cin >> choice;

    if (choice == 1) {
        system("clear");
        cout << "Voltando ao Menu Principal..." << endl;
        sleep(2);
        system("clear");
        return;
    } else if (choice == 2){
        system("clear");
        removerAstronautaVoo();
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        sleep(2);
        system("clear");
        return;
    }
}

void FuncoesMenu::lancarVoo(){
    system("clear");
    int codigoVoo;
    int choice;
    bool verifica = false;

    cout << "Informe o código do voo que deseja lançar: ";
    cin >> codigoVoo;

    if (codigoVoos.find(codigoVoo) != codigoVoos.end()) {
        Voo& voo = codigoVoos[codigoVoo];

        if (voo.getStatus() != 'p') {
            cout << "Não é possível lançar o voo, pois ele não está em planejamento." << endl;
            sleep(2);
            system("clear");
            return;
        }

        bool podeLancar = true;
        int cont = 0;

        //Determina a quantidade de passageiros no voo
        for (auto& passageirosVoo : passageirosVoo) {
            if (passageirosVoo.first == voo.getCodigo()) {
                cont++;
            }
        }

        //Verifica se o voo não está vazio
        if ((cont > 0)) { 
            //verifica disponibilidade dos passageiros   
            for (auto it = passageirosVoo.find(voo.getCodigo()); it != passageirosVoo.upper_bound(voo.getCodigo()); ++it) {
                if (it->second.getDisponibilidade() == false) {
                    podeLancar = false;
                    break;
                }
            }

            //Lança o voo
            if (podeLancar) {
                cout << "Voo lançado com sucesso." << endl;
                //Atualiza status do voo
                voo.setStatus('c');
                //Atualiza a disponibilidade dos astronautas no voo
                for (auto it = passageirosVoo.find(voo.getCodigo()); it != passageirosVoo.upper_bound(voo.getCodigo()); ++it) {
                    
                    for (auto& astronauta : astronautas) {
                        if (it->second.getCpf() == astronauta.getCpf()) {
                            astronauta.setDisponibilidade(false);
                            astronauta.adicionarVooAoHistorico(voo.getCodigo());
                            break;
                        }
                    }
                    
                    for (auto& passageiroVoo : passageirosVoo) {
                        if (it->second.getCpf() == passageiroVoo.second.getCpf()) {
                            passageiroVoo.second.setDisponibilidade(false);
                        }
                    }
                }
            } else {
                cout << "Verifique a disponibilidade dos astronautas antes, ou remova algum(ns) dele(s) do voo." << endl;
            }
        } else {
            cout << "Não é possível lançar um voo vazio." << endl;
        }
    } else {
        cout << "O voo não foi encontrado." << endl;
        sleep(2);
        system("clear");
        lancarVoo();
    }
    
    cout << "Deseja retornar ao menu inicial?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Não" << endl;
    cout << "Escolha uma opção: ";
    cin >> choice;

    if (choice == 1) {
        system("clear");
        cout << "Voltando ao Menu Principal..." << endl;
        sleep(2);
        system("clear");
        return;
    } else if (choice == 2){
        system("clear");
        lancarVoo();
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        sleep(2);
        system("clear");
        return;
    }
}

void FuncoesMenu::explodirVoo(){
    system("clear");
    int codigoVoo;
    int choice;
    bool verifica = false;

    cout << "Informe o código do voo que deseja explodir: ";
    cin >> codigoVoo;

    if (codigoVoos.find(codigoVoo) != codigoVoos.end()) {
        Voo& voo = codigoVoos[codigoVoo];

        if (voo.getStatus() != 'c') {
            cout << "Não é possível explodir o voo, pois ele não está em curso." << endl;
            sleep(2);
            system("clear");
            return;
        }

        cout << "Voo " << voo.getCodigo() << " explodido com sucesso." << endl;
        voo.setStatus('e');

        for (auto it = passageirosVoo.find(voo.getCodigo()); it != passageirosVoo.upper_bound(voo.getCodigo()); ++it) {
            
            for (auto& astronauta : astronautas) {
                if (it->second.getCpf() == astronauta.getCpf()) {
                    astronauta.setVivo(false);
                    break;
                }
            }
            
            for (auto& passageiroVoo : passageirosVoo) {
                if (it->second.getCpf() == passageiroVoo.second.getCpf()) {
                    passageiroVoo.second.setVivo(false);
                }
            }
        }

    } else {
        cout << "O voo não foi encontrado." << endl;
        sleep(2);
        system("clear");
        lancarVoo();
    }
    
    cout << "Deseja retornar ao menu inicial?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Não" << endl;
    cout << "Escolha uma opção: ";
    cin >> choice;

    if (choice == 1) {
        system("clear");
        cout << "Voltando ao Menu Principal..." << endl;
        sleep(2);
        system("clear");
        return;
    } else if (choice == 2){
        system("clear");
        explodirVoo();
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        sleep(2);
        system("clear");
        return;
    }
}

void FuncoesMenu::finalizarVoo(){
    system("clear");
    int codigoVoo;
    int choice;
    bool verifica = false;

    cout << "Informe o código do voo que deseja finalizar: ";
    cin >> codigoVoo;

    if (codigoVoos.find(codigoVoo) != codigoVoos.end()) {
        Voo& voo = codigoVoos[codigoVoo];

        if (voo.getStatus() != 'c') {
            cout << "Não é possível finalizar o voo, pois ele não está em curso." << endl;
            sleep(2);
            system("clear");
            return;
        }

        cout << "Voo " << voo.getCodigo() << " finalizado com sucesso." << endl;
        voo.setStatus('f');

        for (auto it = passageirosVoo.find(voo.getCodigo()); it != passageirosVoo.upper_bound(voo.getCodigo()); ++it) {
            
            for (auto& astronauta : astronautas) {
                if (it->second.getCpf() == astronauta.getCpf()) {
                    astronauta.setDisponibilidade(true);
                    break;
                }
            }
            
            for (auto& passageiroVoo : passageirosVoo) {
                if (it->second.getCpf() == passageiroVoo.second.getCpf()) {
                    passageiroVoo.second.setDisponibilidade(true);
                }
            }
        }

    } else {
        cout << "O voo não foi encontrado." << endl;
        sleep(2);
        system("clear");
        finalizarVoo();
    }
    
    cout << "Deseja retornar ao menu inicial?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Não" << endl;
    cout << "Escolha uma opção: ";
    cin >> choice;

    if (choice == 1) {
        system("clear");
        cout << "Voltando ao Menu Principal..." << endl;
        sleep(2);
        system("clear");
        return;
    } else if (choice == 2){
        system("clear");
        finalizarVoo();
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        sleep(2);
        system("clear");
        return;
    }
}

void FuncoesMenu::listarVoo() {
    system("clear");
    int choice;

    cout << "=== Voos em planejamento ===" << endl;
    for (auto& it : codigoVoos) {
        if (it.second.getStatus() == 'p') {
            cout << "   Voo: " << it.first << endl;
            cout << "   Astronautas no voo:" << endl;    
            for (auto itp = passageirosVoo.find(it.first); itp != passageirosVoo.upper_bound(it.first); ++itp) {
                cout << "       Nome: " << itp->second.getNome() << ", Cpf: " << itp->second.getCpf() << ", Idade: " << itp->second.getIdade() << endl;
            }
        } 
    }

    cout << "=== Voos em curso ===" << endl;
    for (auto& it : codigoVoos) {
        if (it.second.getStatus() == 'c') {
            cout << "   Voo: " << it.first << endl;
            cout << "   Astronautas no voo:" << endl;    
            for (auto itp = passageirosVoo.find(it.first); itp != passageirosVoo.upper_bound(it.first); ++itp) {
                cout << "       Nome: " << itp->second.getNome() << ", Cpf: " << itp->second.getCpf() << ", Idade: " << itp->second.getIdade() << endl;
            }
        } 
    }

    cout << "=== Voos finalizados sem sucesso ===" << endl;
    for (auto& it : codigoVoos) {
        if (it.second.getStatus() == 'e') {
            cout << "   Voo: " << it.first << endl;
            cout << "   Astronautas no voo:" << endl;    
            for (auto itp = passageirosVoo.find(it.first); itp != passageirosVoo.upper_bound(it.first); ++itp) {
                cout << "       Nome: " << itp->second.getNome() << ", Cpf: " << itp->second.getCpf() << ", Idade: " << itp->second.getIdade() << endl;
            }
        } 
    }

    cout << "=== Voos finalizados com sucesso ===" << endl;
    for (auto& it : codigoVoos) {
        if (it.second.getStatus() == 'f') {
            cout << "   Voo: " << it.first << endl;
            cout << "   Astronautas no voo:" << endl;    
            for (auto itp = passageirosVoo.find(it.first); itp != passageirosVoo.upper_bound(it.first); ++itp) {
                cout << "       Nome: " << itp->second.getNome() << ", Cpf: " << itp->second.getCpf() << ", Idade: " << itp->second.getIdade() << endl;
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
        sleep(2);
        system("clear");
        return;
    } else if (choice == 2){
        system("clear");
        listarVoo();
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        sleep(2);
        system("clear");
        return;
    }
}

void FuncoesMenu::listarAstronautasMortos(){
    system("clear");
    int choice;
    cout << "=== Astronautas Mortos ===" << endl;
    
    for (auto& astronauta : astronautas) {
        if (astronauta.getVivo() == false) {
            cout << "Nome: " << astronauta.getNome() << ", CPF: " << astronauta.getCpf() << endl;
            list<int> voos = astronauta.getHistorico();
            cout << "Voos que participou: " << endl;
            for (auto& voo : voos) {
                cout << voo << endl;
            }
            cout << "" << endl;
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
        sleep(2);
        system("clear");
        return;
    } else if (choice == 2){
        system("clear");
        listarAstronautasMortos();
    } else {
        cout << "Valor inválido. Voltando ao Menu Principal..." << endl;
        sleep(2);
        system("clear");
        return;
    }