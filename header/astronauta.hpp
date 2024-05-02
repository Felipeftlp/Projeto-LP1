#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <string>

using namespace std;

class Astronauta {
    private:
        string cpf;
        string nome;
        int idade;
        bool vivo = true;
        bool disponibilidade = true;

    public:
        Astronauta(string cpf, string nome, int idade);

        string getCpf();

        string getNome();

        int getIdade();

        bool getVivo();

        bool getDisponibilidade();

        void setCpf(string cpf);

        void setNome(string nome);

        void setIdade(int idade);

        void setVivo(bool vivo);

        void setDisponibilidade(bool disponibilidade);
};

#endif