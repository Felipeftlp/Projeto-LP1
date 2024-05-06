#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <string>
#include <list>

using namespace std;

class Astronauta {
    private:
        string cpf;
        string nome;
        int idade;
        bool vivo = true;
        bool disponibilidade = true;
        list<int> voos;

    public:
        Astronauta(string cpf, string nome, int idade);
        
        string getCpf();

        string getNome();

        int getIdade();

        bool getVivo();

        bool getDisponibilidade();

        list<int> getHistorico();

        void setCpf(string cpf);

        void setNome(string nome);

        void setIdade(int idade);

        void setVivo(bool vivo);

        void setDisponibilidade(bool disponibilidade);

        void adicionarVooAoHistorico(int codigoVoo);
};

#endif