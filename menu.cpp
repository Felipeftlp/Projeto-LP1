#include <iostream>
#include <list>
#include <string>
#include "header/astronauta.hpp"
#include "header/voo.hpp"
#include "header/funcoesMenu.hpp"
//#include "header/gerenciamentoVoo.hpp"

using namespace std;

int main() {

    FuncoesMenu funcoesMenu;
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
                funcoesMenu.cadastrarAstronautas();
                break;
            case 2:
                funcoesMenu.cadastrarVoos();
                break;
            case 3:
                funcoesMenu.adicionarAtronautaVoo();
                break;
            case 4:
                funcoesMenu.removerAstronautaVoo();
                break;
            case 5:
                funcoesMenu.lancarVoo();
                break;
            case 6:
                funcoesMenu.explodirVoo();
                break;
            case 7:
                funcoesMenu.finalizarVoo();
                break;
            case 8:
                funcoesMenu.listarVoo();
                break;
            case 9:
                funcoesMenu.listarAstronautasMortos();
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