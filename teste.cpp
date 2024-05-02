#include <iostream>
#include <string>
#include <list>
#include <unordered_map>

using namespace std;

// Definição da classe Astronauta
class Astronauta {
private:
    string cpf;
    string nome;
    int idade;

public:
    Astronauta(string _cpf, string _nome, int _idade) : cpf(_cpf), nome(_nome), idade(_idade) {}

    string getCPF() const { return cpf; }
    string getNome() const { return nome; }
    int getIdade() const { return idade; }
};

// Definição da classe Voo
class Voo {
private:
    int codigoVoo;
    list<Astronauta*> passageiros;
    bool planejamento;

public:
    Voo(int _codigoVoo) : codigoVoo(_codigoVoo), planejamento(true) {}

    int getCodigoVoo() const { return codigoVoo; }

    void adicionarPassageiro(Astronauta* astronauta) {
        if (planejamento) {
            passageiros.push_back(astronauta);
        } else {
            cout << "Não é possível adicionar passageiros durante o voo." << endl;
        }
    }

    void removerPassageiro(string cpf) {
        if (planejamento) {
            for (auto it = passageiros.begin(); it != passageiros.end(); ++it) {
                if ((*it)->getCPF() == cpf) {
                    passageiros.erase(it);
                    cout << "Astronauta removido do voo." << endl;
                    return;
                }
            }
            cout << "Astronauta não encontrado no voo." << endl;
        } else {
            cout << "Não é possível remover passageiros durante o voo." << endl;
        }
    }

    void lancarVoo() {
        if (passageiros.size() > 0 && planejamento) {
            planejamento = false;
            cout << "Voo lançado com sucesso." << endl;
        } else {
            cout << "Não é possível lançar o voo." << endl;
        }
    }

    void explodirVoo() {
        if (!planejamento) {
            for (Astronauta* astronauta : passageiros) {
                cout << "Astronauta " << astronauta->getNome() << " morreu." << endl;
            }
            passageiros.clear();
        }
    }

    void finalizarVoo(bool sucesso) {
        if (!planejamento) {
            if (sucesso) {
                cout << "Voo finalizado com sucesso." << endl;
            } else {
                explodirVoo();
                cout << "Voo finalizado sem sucesso." << endl;
            }
            planejamento = true;
        } else {
            cout << "O voo ainda está em planejamento." << endl;
        }
    }

    list<Astronauta*> getPassageiros() const { return passageiros; }
};

// Definição da classe Sistema
class Sistema {
private:
    unordered_map<string, Astronauta*> astronautas;
    list<Voo*> voos;

public:
    void cadastrarAstronauta(string cpf, string nome, int idade) {
        if (astronautas.find(cpf) == astronautas.end()) {
            Astronauta* novoAstronauta = new Astronauta(cpf, nome, idade);
            astronautas[cpf] = novoAstronauta;
            cout << "Astronauta cadastrado com sucesso." << endl;
        } else {
            cout << "Astronauta já cadastrado." << endl;
        }
    }

    void cadastrarVoo(int codigoVoo) {
        Voo* novoVoo = new Voo(codigoVoo);
        voos.push_back(novoVoo);
        cout << "Voo cadastrado com sucesso." << endl;
    }

    void adicionarAstronautaEmVoo(string cpf, int codigoVoo) {
        if (astronautas.find(cpf) != astronautas.end()) {
            for (auto it = voos.begin(); it != voos.end(); ++it) {
                if ((*it)->getCodigoVoo() == codigoVoo) {
                    (*it)->adicionarPassageiro(astronautas[cpf]);
                    return;
                }
            }
            cout << "Voo não encontrado." << endl;
        } else {
            cout << "Astronauta não encontrado." << endl;
        }
    }

    void removerAstronautaDeVoo(string cpf, int codigoVoo) {
        for (auto it = voos.begin(); it != voos.end(); ++it) {
            if ((*it)->getCodigoVoo() == codigoVoo) {
                (*it)->removerPassageiro(cpf);
                return;
            }
        }
        cout << "Voo não encontrado." << endl;
    }

    void listarVoos() {
        for (Voo* voo : voos) {
            cout << "Código do Voo: " << voo->getCodigoVoo() << endl;
            cout << "Passageiros: ";
            for (Astronauta* astronauta : voo->getPassageiros()) {
                cout << astronauta->getNome() << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Sistema sistema;
    string cpf;
    string nome;
    int idade;

    sistema.cadastrarVoo(1);

    cout << "Informe o cpf do astronauta " << endl;
    cin >> cpf;
    cout << "Informe o nome do astronauta " << endl;
    cin >> nome;
    cout << "Informe a idade do astronauta " << endl;
    cin >> idade;

    sistema.cadastrarAstronauta(cpf, nome, idade);
    sistema.adicionarAstronautaEmVoo(cpf, 1);

    cout << "Informe o cpf do astronauta " << endl;
    cin >> cpf;
    cout << "Informe o nome do astronauta " << endl;
    cin >> nome;
    cout << "Informe a idade do astronauta " << endl;
    cin >> idade;

    sistema.cadastrarAstronauta(cpf, nome, idade);

    sistema.adicionarAstronautaEmVoo(cpf, 1);

    sistema.listarVoos();

    return 0;
}
