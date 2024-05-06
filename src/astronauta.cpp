#include "../header/astronauta.hpp"

using namespace std;

Astronauta::Astronauta(string cpf, string nome, int idade){
    this->cpf = cpf;
    this->nome = nome;
    this->idade = idade;
    this->disponibilidade = true;
    this->vivo = true;
}

//Métodos getters
string Astronauta::getCpf(){
    return cpf;
}

string Astronauta::getNome(){
    return nome;
}

int Astronauta::getIdade(){
    return idade;
}

bool Astronauta::getVivo(){
    return vivo;
}

bool Astronauta::getDisponibilidade(){
    return disponibilidade;
}

list<int> Astronauta::getHistorico(){
    return voos;
}

//Métodos setters
void Astronauta::setCpf(string cpf){
    this->cpf = cpf;
}

void Astronauta::setNome(string nome){
    this->nome = nome;
}

void Astronauta::setIdade(int idade){
    this->idade = idade;
}

void Astronauta::setVivo(bool vivo){
    this->vivo = vivo;
}

void Astronauta::setDisponibilidade(bool disponibilidade){
    this->disponibilidade = disponibilidade;
}

void Astronauta::adicionarVooAoHistorico(int codigoVoo){
    this->voos.push_back(codigoVoo);
}