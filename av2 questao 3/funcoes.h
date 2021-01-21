#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void criar(FILE *arq)
{
    string titulo;
    char arquivo[30];
    cout << "Digite o nome do arquivo a ser criado .dat: ";
    cin >> arquivo;
    if ((arq = fopen(arquivo, "w+b")) == NULL)
    {
        cout << "Erro na abertura";
    }
    cout << "Digite o titulo do arquivo: ";
    cin.ignore();
    getline(cin, titulo);
    fwrite(&titulo, sizeof(titulo), 1, arq);
    fclose(arq);
}

void inserir(FILE *arq)
{
    string texto;
    char arquivo[30];
    cout << "Digite o nome do arquivo a ser criado para inserir dados .dat: ";
    cin >> arquivo;
    if ((arq = fopen(arquivo, "ab")) == NULL)
    {
        cout << "Nao foi possivel abrir o arquivo";
    }

    cout << "Digite um nome: ";
    cin.ignore();
    getline(cin, texto);
    fwrite(&texto, sizeof(texto), 1, arq);

    fclose(arq);
}
void exibir(FILE *arq)
{
    string ch;
    char arquivo[30];
    cout << "Digite o nome do arquivo a ser exibido .dat: ";
    cin >> arquivo;
    if ((arq = fopen(arquivo, "rb")) == NULL)
    {
        cout << "Nao foi possivel abrir o arquivo";
    }
    while (!feof(arq))
    {
        cout << ch << endl;
        fread(&ch, sizeof(string), 1, arq);
    }

    fclose(arq);
}
void posicaocorrente(FILE *arq)
{
    long posicao;
    char arquivo[30];
    cout << "Digite o nome do arquivo a ser mensurado .dat: ";
    cin >> arquivo;
    if ((arq = fopen(arquivo, "rb")) == NULL)
    {
        cout << "Nao foi possivel abrir o arquivo";
    }
    fseek(arq, 0, SEEK_END);
    posicao = ftell(arq);
    fclose(arq);
    cout << "Tamanho do arquivo: " << posicao << endl;
}

void apagar()
{
    char op, apagar[30];
    cout << "Deseja apagar o arquivo?" << endl;
    cout << "S- sim" << endl;
    cout << "N- nao" << endl
         << ": ";
    fflush(stdout);
    cin >> op;
    cout << "Digite o nome do arquivo a ser apagado: ";
    cin >> apagar;
    if (toupper(op) == 'S' || toupper(op) == 's')
    {
        if (remove(apagar))
        {
            cout << "Erro ao tentar apagar arquivo" << endl;
        }
        else
        {
            cout << "Arquivo apagado com sucesso" << endl;
        }
    }
}
void renomear()
{
    char atual[30], novo[30];
    cout << "Digite o nome atual do arquivo: ";
    cin >> atual;

    cout << "Digite o nome novo do arquivo: ";
    cin >> novo;

    if (rename(atual, novo))
    {
        cout << "Erro ao renomear" << endl;
    }
    else
    {
        cout << "renomeado com sucesso" << endl;
    }
}
void renomeartitulo(FILE *arq)
{
    string texto;
    char arquivo[30];
    cout << "Digite o nome do arquivo a ser aberto: ";
    cin >> arquivo;
    if ((arq = fopen(arquivo, "r+b")) == NULL)
    {
        cout << "Nao foi possivel abrir o arquivo";
    }

    cout << "Digite o novo titulo no topo do arquivo: ";
    cin.ignore();
    getline(cin, texto);
    rewind(arq);
    fwrite(&texto, sizeof(texto), 1, arq);

    fclose(arq);
}
void error(FILE *arq)
{
    char arquivo[30], x[30];
    cout << "Digite o nome do arquivo a ser aberto: ";
    cin >> arquivo;
    if ((arq = fopen(arquivo, "rb")) == NULL)
    {
        cout << "Nao foi possivel abrir o arquivo";
    }
    else
    {
        cout << "Digite algo: ";
        cin >> x;
        fwrite(&x, sizeof(x), 1, arq);
        if (ferror(arq))
            cout << "Tentou escrever em um arquivo so de leitura" << endl;
        fclose(arq);
    }
}
