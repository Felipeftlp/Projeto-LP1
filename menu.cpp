#include <iostream>
//#include <list>
//#include <unordered_map>
#include "header/astronauta.hpp"
#include "header/voo.hpp"
#include "header/funcoesMenu.hpp"
#include "header/gerenciamentoVoo.hpp"

using namespace std;

int main() {
//    GerenciamentoVoo gerenciamentoVoo;
    unordered_map<string, Astronauta> astronautas;
    //list<Astronauta*> astronautas;
    list<Voo> voos;
    setlocale(LC_ALL, "pt_BR");

    int choice;

    do {
        cout << "\n=== Menu ===\n";  
        cout << "1 - Cadastrar astronauta\n";
        cout << "2 - Cadastrar voo\n";
        cout << "3 - Adicionar astronauta em voo\n";
        cout << "4 - Remover astronauta de um voo\n";
        cout << "5 - Lançar um voo\n";
        cout << "6 - Explodir voo\n";
        cout << "7 - Finalizar voo\n";
        cout << "8 - Listar todos os voos\n";
        cout << "9 - Listar todos os astronautas mortos\n";
        cout << "0 - Sair\n";

        cout << "Escolha uma opcao: "; 
        cin >> choice;

        switch (choice) {
            case 1:
                cadastrarAstronautas(astronautas);
                break;
            case 2:
                cadastrarVoos(voos);
                break;
            case 3:
                adicionarAtronautaVoo(voos, astronautas);
                break;
            case 4:
                //removerAstronautaVoo(astronautas, voos);
                break;
            case 5:
                //lancarVoo(voos);
                break;
            case 6:
                //explodirVoo(voos);
                break;
            case 7:
                //finalizarVoo(astronautas, voos);
                break;
            case 8:
                //listarVoo(astronautas, voos);
                break;
            case 9:
                //listarAstronautasMortos(astronautas);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (choice != 0);

    return 0;
}