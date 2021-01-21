#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>


using namespace std;

struct empresa
{
    char name[100], idade[100], sal[100];
};

void criar(FILE *arq)
{
    if((arq = fopen("Banco_de_dados.txt", "w+")) == NULL)
    {
        cout << "arquivo nao pode ser aberto";
    } 
}
void inserir(FILE *arq)
{
    struct empresa people;
   if ((arq = fopen("Banco_de_dados.txt", "a")) == NULL)
    {
        cout << "arquivo nao pode ser aberto";
    }
    cout << "Nome: ";
    cin >> people.name;

    cout << "Idade: ";
    cin >> people.idade;

    cout << "Salario: ";
    cin >> people.sal;

        fputs(people.name, arq);
        fputs("\n", arq);
        fputs(people.idade, arq);
        fputs("\n", arq);
        fputs(people.sal, arq);
        fputs("\n\n", arq);
        fclose(arq);
}

void exibir(FILE *arq)
{
    char linha[100];

    if ((arq = fopen("Banco_de_dados.txt", "r")) == NULL)
    {
        cout << "arquivo nao pode ser aberto";
    }
    
    fgets(linha, 100, arq);
    while (!feof(arq))
    {
        cout << "  "<< linha;
        fgets(linha, 100, arq);       
    }
    fclose(arq);
}
void apagar (FILE *arq)
{
    if((arq = fopen("Banco_de_dados.txt", "w+")) == NULL)
    {
        cout << "arquivo nao pode ser aberto";
    } 
}