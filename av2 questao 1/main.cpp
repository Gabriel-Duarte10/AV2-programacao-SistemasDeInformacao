#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "funcoes.h"


using namespace std;


int main ()
{
    FILE *arq;
    int op;
     
    do
    {
        cout << " 0 - Criar arquivo se nao estiver criado" << endl;
        cout << " 1 - Inserir" << endl;
        cout << " 2 - Exibir" << endl; 
        cout << " 3 - Excluir todos os dados" << endl;
        cout << " : ";
        cin >> op;
        switch (op)
        {
            case 0: criar(arq); break;
            case 1: inserir(arq); break;
            case 2: exibir(arq); break;
            case 3: apagar(arq); break;
        }
        system("pause");
        system("cls");
    } while (op>=0 && op<=3);

    fclose(arq);
    return 0;
}