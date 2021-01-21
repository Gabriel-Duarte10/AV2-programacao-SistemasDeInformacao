#include <iostream>
#include <stdlib.h>
#include "funcoes.h"

using namespace std;

int main()
{
    int op;
    FILE *arquivo;

    do
    {
        cout << "-------Menu------- " << endl;
        cout << " 0- Criar arquivo" << endl;
        cout << " 1- Inserir dados " << endl;
        cout << " 2- Exibir dados" << endl;
        cout << " 3- Tamanho do arquivo" << endl;
        cout << " 4- Apagar arquivo" << endl;
        cout << " 5- renomear arquivo" << endl;
        cout << " 6- Renomear titulo" << endl;
        cout << " 7- Teste de error" << endl;
        cout << "opcao: ";
        cin >> op;
        switch (op)
        {
        case 0:
            criar(arquivo);
            break;
        case 1:
            inserir(arquivo);
            break;
        case 2:
            exibir(arquivo);
            break;
        case 3:
            posicaocorrente(arquivo);
            break;
        case 4:
            apagar();
            break;
        case 5:
            renomear();
            break;

        case 6:
            renomeartitulo(arquivo);
            break;
        case 7:
            error(arquivo);
            break;
        }
        system("pause");
        system("cls");

    } while (op >= 0 && op <= 7);

    fclose(arquivo);
    return 0;
}