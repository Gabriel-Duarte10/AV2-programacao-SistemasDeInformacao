#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

int menu()
{
    int op;
    cout << " 0 - Criar arquivo .dar se for seu primeiro acesso" << endl;
    cout << " 1 - Inserir dados da consulta" << endl;
    cout << " 2 - Exibir consultas" << endl;
    cout << " 3 - Consultar atendimentos" << endl;
    cout << " 4 - Finalizar programa" << endl;
    cin >> op;
    return op;
}
void criar(FILE *arq)
{
    if ((arq = fopen("dados-consulta.dat", "w+b")) == NULL)
    {
        cout << "arquivo nao pode ser aberto";
    }
}
void inserirmenu(FILE *arq)
{
    string nome;
    if ((arq = fopen("dados-consulta.dat", "ab")) == NULL)
    {
        cout << "arquivo nao pode ser aberto";
    }

    nome = "Nome do dono";
    fwrite(&nome, sizeof(nome), 1, arq);
    nome = "\t";
    fwrite(&nome, sizeof(nome), 1, arq);
    nome = "Nome do pet";
    fwrite(&nome, sizeof(nome), 1, arq);
    nome = "\t";
    fwrite(&nome, sizeof(nome), 1, arq);
    nome = "Nascimento";
    fwrite(&nome, sizeof(nome), 1, arq);
    nome = "\t";
    fwrite(&nome, sizeof(nome), 1, arq);
    nome = "atendimento";
    fwrite(&nome, sizeof(nome), 1, arq);
    nome = "\t";
    fwrite(&nome, sizeof(nome), 1, arq);
    nome = "valor";
    fwrite(&nome, sizeof(nome), 1, arq);
    nome = "\n";
    fwrite(&nome, sizeof(nome), 1, arq);

    fclose(arq);
}

void iniciaratendimento(char *nomedono, char *nomeanimal, FILE *arq2)
{
    char arquivo[100];
    char texto2[1000];
    string texto;
    strcpy(arquivo, nomeanimal);
    strcat(arquivo, nomedono);
    if ((arq2 = fopen(arquivo, "w")) == NULL)
    {
        cout << "arquivo nao pode ser aberto";
    }
    cout << "Dados de atendimento: ";
    cin.ignore();
    getline(cin, texto);
    strcpy(texto2, texto.c_str());

    fputs(texto2, arq2);
    fclose(arq2);
}

void inserirconsul(FILE *arq, FILE *arq2)
{
    string nome;
    char nomedono[100], nomeanimal[100];
    if ((arq = fopen("dados-consulta.dat", "ab")) == NULL)
    {
        cout << "arquivo nao pode ser aberto";
    }

    cout << "Digite o nome do dono: ";
    cin >> nome;
    fwrite(&nome, sizeof(nome), 1, arq);
    strcpy(nomedono, nome.c_str());
    strcat(nomedono, ".txt");
    nome = "\t\t";
    fwrite(&nome, sizeof(nome), 1, arq);

    cout << "Digite o nome do animal: ";
    cin >> nome;
    fwrite(&nome, sizeof(nome), 1, arq);
    strcpy(nomeanimal, nome.c_str());
    nome = "\t\t";
    fwrite(&nome, sizeof(nome), 1, arq);

    cout << "Digite a data de nascimento do pet EX:10/10/2020 "
         << ": ";
    cin >> nome;
    fwrite(&nome, sizeof(nome), 1, arq);
    nome = "\t";
    fwrite(&nome, sizeof(nome), 1, arq);

    cout << "Digite a data do atendimento EX:10/10/2020 "
         << ": ";
    cin >> nome;
    fwrite(&nome, sizeof(nome), 1, arq);
    nome = "\t";
    fwrite(&nome, sizeof(nome), 1, arq);

    cout << "Digite o valor da consulta "
         << ": ";
    cin >> nome;
    fwrite(&nome, sizeof(nome), 1, arq);
    nome = "\n";
    fwrite(&nome, sizeof(nome), 1, arq);
    system("pause");
    system("cls");
    
    iniciaratendimento(nomedono, nomeanimal, arq2);
    fclose(arq);
}

void exibirconsultas(FILE *arq)
{
    string ch;
    if ((arq = fopen("dados-consulta.dat", "rb")) == NULL)
    {
        cout << "arquivo nao pode ser aberto";
    }
    while (!feof(arq))
    {
        cout << ch;
        fread(&ch, sizeof(string), 1, arq);
    }
    cout << endl;

    fclose(arq);
}
void colsultaratendimentos(FILE *arq2)
{
    char arquivo[50], nomeanimal[30], nomedono[30], linha[100];

    cout << "Digite o nome do dono: ";
    cin >> nomedono;
    strcat(nomedono, ".txt");
    cout << "digite o nome do animal: ";
    cin >> nomeanimal;
    strcpy(arquivo, nomeanimal);
    strcat(arquivo, nomedono);

    if ((arq2 = fopen(arquivo, "r")) == NULL)
    {
        cout << "arquivo nao pode ser aberto";
    }

   //fgets(linha, 100, arq2);
    while (!feof(arq2))
    {
        fgets(linha, 100, arq2);
        cout << "  " << linha;
    }
    cout << "\n"; 

    fclose(arq2);
}
