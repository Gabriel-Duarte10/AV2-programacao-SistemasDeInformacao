#include <iostream>
#include <stdlib.h>
#include "funcoes.h"

using namespace std;

int main()
{
    FILE *arquivo;
    FILE *arquivo2;
    int op;
    do
    {
        op = menu();
        switch (op)
        {
        case 0:
            criar(arquivo);
            inserirmenu(arquivo);
            break;
        case 1:
            inserirconsul(arquivo, arquivo2);
            break;
        case 2:
            exibirconsultas(arquivo);
            break;
        case 3:
            colsultaratendimentos(arquivo2);
            break;
        }
    	system("pause");
        system("cls");
    } while (op >= 0 && op <= 3);

    return 0;
    fclose(arquivo);
    fclose(arquivo2);
}