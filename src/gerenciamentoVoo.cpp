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

void GerenciamentoVoo::adicionarAstronautaEmVoo(int codigoVoo, Astronauta &astronauta, multimap<int, Astronauta> &passageiros) {
    passageiros.insert(make_pair(codigoVoo, astronauta));
    cout << "O astronauta " << astronauta.getNome() << " foi adiconado no voo " << codigoVoo << endl;
}

void GerenciamentoVoo::removerAstronautaDeVoo(int codigoVoo, Astronauta &astronauta, bool verifica, multimap<int, Astronauta> &passageiros) {
    auto it = passageiros.find(codigoVoo);
    
    while (it != passageiros.upper_bound(codigoVoo)) {
        if (it->second.getCpf() == astronauta.getCpf()) {
            verifica = true;
            it = passageiros.erase(it);
        } else {
            ++it;
        }
    }

    if (verifica) {
        cout << "Astronauta removido" << endl;
    } else {
        cout << "O astronauta não existe ou não está no voo informado" << endl;
    }
}

void GerenciamentoVoo::lancarVoo(Voo &voo, list<Astronauta> &astronautas, multimap<int, Astronauta> &passageiros) {
    bool podeLancar = true;
    int cont = 0;

    for (auto it = passageiros.begin(); it != passageiros.end(); ++it) {
        if (it->first == voo.getCodigo()) {
            cont++;
        }
    }

    if ((cont > 0) && (voo.getStatus() == 'p')) {    
        for (auto it = passageiros.find(voo.getCodigo()); it != passageiros.upper_bound(voo.getCodigo()); ++it) {
            if (it->second.getDisponibilidade() == false) {
                podeLancar = false;
            }
        }

        if (podeLancar) {
            cout << "Voo lançado com sucesso." << endl;
            voo.setStatus('c');
            for (auto it = passageiros.find(voo.getCodigo()); it != passageiros.upper_bound(voo.getCodigo()); ++it) {
                for (auto ita = astronautas.begin(); ita != astronautas.end(); ++ita) {
                    if (it->second.getCpf() == ita->getCpf()) {
                        ita->setDisponibilidade(false);
                        ita->adicionarVooAoHistorico(voo.getCodigo());
                        break;
                    }
                }
                for (auto itp = passageiros.begin(); itp != passageiros.end(); ++itp) {
                    if (it->second.getCpf() == itp->second.getCpf()) {
                        itp->second.setDisponibilidade(false);
                    }
                }
            }
        } else {
            cout << "Verifique a disponibilidade dos astronautas antes, ou remova algum(ns) dele(s) do voo." << endl;
        }
    } else {
        cout << "Não é possível lançar o voo." << endl;
    }
}

void GerenciamentoVoo::explodirVoo(Voo &voo, list<Astronauta> &astronautas, multimap<int, Astronauta> &passageiros) {
    if ((voo.getStatus() == 'c')) {
        cout << "Voo " << voo.getCodigo() << " explodido com sucesso." << endl;
        voo.setStatus('e');

        for (auto it = passageiros.find(voo.getCodigo()); it != passageiros.upper_bound(voo.getCodigo()); ++it) {
            for (auto ita = astronautas.begin(); ita != astronautas.end(); ++ita) {
                if (it->second.getCpf() == ita->getCpf()) {
                    ita->setVivo(false);
                    break;
                }
            }
            for (auto itp = passageiros.begin(); itp != passageiros.end(); ++itp) {
                if (it->second.getCpf() == itp->second.getCpf()) {
                    itp->second.setVivo(false);
                }
            }
        }
    } else {
        cout << "Não é possível explodir o voo." << endl;
    }
}

void GerenciamentoVoo::finalizarVoo(Voo &voo, list<Astronauta> &astronautas, multimap<int, Astronauta> &passageiros) {
    if ((voo.getStatus() == 'c')) {
        cout << "Voo " << voo.getCodigo() << " finalizado com sucesso." << endl;
        voo.setStatus('f');

        for (auto it = passageiros.find(voo.getCodigo()); it != passageiros.upper_bound(voo.getCodigo()); ++it) {
            for (auto ita = astronautas.begin(); ita != astronautas.end(); ++ita) {
                if (it->second.getCpf() == ita->getCpf()) {
                    ita->setDisponibilidade(true);
                    break;
                }
            }
            for (auto itp = passageiros.begin(); itp != passageiros.end(); ++itp) {
                if (it->second.getCpf() == itp->second.getCpf()) {
                    itp->second.setDisponibilidade(true);
                }
            }
        }
    } else {
        cout << "Não é possível explodir o voo." << endl;
    }
}