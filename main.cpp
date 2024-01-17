#include "lista_encadeada.h"

#include <iostream>
#include <string>

using namespace std;

const char *SENHA_PARA_MANUTENCAO = "senhafraca";

void AdicionarParada();
void AlterarParada();
bool AutenticaUsuario();
NoDuplamenteEncadeavel *CriarNovaParada();
void MostrarTodasAsLinhas();
void OpcoesDeManutencao();
void RealizarManutencao();
void ProcurarLinhaDeOnibus();
void RemoverLinha();
void RemoverParada();

ListaEncadeada linhas_de_onibus;

int main()
{
    int escolha = -1;
    do
    {
        cout << "O que voce deseja fazer?" << endl;
        cout << "  0. Encerrar o programa e sair" << endl;
        cout << "  1. Procurar uma linha de onibus" << endl;
        cout << "  2. Realizar manutencao do programa" << endl;

        cin >> escolha;
        switch (escolha)
        {
        case 1:
            ProcurarLinhaDeOnibus();
            break;
        case 2:
            RealizarManutencao();
            break;
        default:
            break;
        }
    } while (escolha != 0);

    linhas_de_onibus.ImprimeDadosFormatados();

    return 0;
}

void AlterarParada()
{
    cout << "De qual linha você quer alterar uma parada?" << endl;
    cout << "Numero da linha: ";
    unsigned numero_da_linha;
    cin >> numero_da_linha;
    NoEncadeavel *linha = linhas_de_onibus.BuscaLinhaPeloNumero(numero_da_linha);
    if (linha == nullptr)
    {
        cout << "Indique uma linha cadastrada." << endl;
        return;
    }
    if (linha->paradas->EstaVazia())
    {
        cout << "A lista de paradas da linha " << linha->numero_da_linha
             << " - " << linha->nome_da_companhia
             << " esta vazia. Nao ha paradas para alterar." << endl;
        return;
    }
    linha->paradas->ImprimeParadasNumeradas();
    cout << "Qual parada voce quer alterar?" << endl;
    cout << "Indice da parada: ";
    unsigned indice_da_parada;
    cin >> indice_da_parada;
    if (indice_da_parada > linha->paradas->RecuperaTamanho() || indice_da_parada < 1)
    {
        cout << "Indice invalido. Escolha uma parada entre " << linha->paradas->RecuperaTamanho() << " parada(s) existente(s)." << endl;
        return;
    }
    cout << "Novo nome da parada: ";
    string novo_nome;
    getline(cin >> ws, novo_nome);
    cout << "Novo horario de chegada: ";
    string novo_horario_de_chegada;
    getline(cin >> ws, novo_horario_de_chegada);
    cout << "Novo horario de partida: ";
    string novo_horario_de_partida;
    getline(cin >> ws, novo_horario_de_partida);
    linha->paradas->AlteraParadaPeloIndice(indice_da_parada, novo_nome, novo_horario_de_chegada, novo_horario_de_partida);
}

void MostrarTodasAsLinhas()
{
    linhas_de_onibus.ImprimeDadosFormatados();
}

void ProcurarLinhaDeOnibus()
{
    cout << "Essa funcao ainda nao foi implementada..." << endl;
}

void OpcoesDeManutencao()
{
    cout << "O que voce deseja fazer?" << endl;
    cout << "  0. Encerrar manutencao do programa" << endl;
    cout << "  1. Adicionar uma linha de onibus" << endl;
    cout << "  2. Mostrar todas as linhas de onibus" << endl;
    cout << "  3. Remover uma linha de onibus" << endl;
    cout << "  4. Adicionar uma parada em uma linha" << endl;
    cout << "  5. Alterar uma parada em uma linha" << endl;
    cout << "  6. Remover uma parada em uma linha" << endl;
}

bool AutenticaUsuario()
{
    string senha_do_usuario;
    cout << "Senha para manutencao: ";
    getline(cin >> ws, senha_do_usuario);
    if (senha_do_usuario == SENHA_PARA_MANUTENCAO)
    {
        return true;
    }
    return false;
}

void RealizarManutencao()
{
    bool usuario_autenticado = AutenticaUsuario();
    if (!usuario_autenticado)
    {
        return;
    }

    int escolha = -1;
    do
    {
        OpcoesDeManutencao();
        cin >> escolha;
        switch (escolha)
        {
        case 1:
        {
            unsigned numero;
            string companhia;
            cout << "Numero da linha: ";
            cin >> numero;
            cout << "Nome da companhia: ";
            getline(cin >> ws, companhia);
            linhas_de_onibus.AdicionaNovaLinhaOrdenadamente(numero, companhia);
            break;
        }
        case 2:
            MostrarTodasAsLinhas();
            break;
        case 3:
            RemoverLinha();
            break;
        case 4:
            AdicionarParada();
            break;
        case 5:
            AlterarParada();
            break;
        case 6:
            RemoverParada();
            break;
        default:
            break;
        }
    } while (escolha != 0);
}

void AdicionarParada()
{
    cout << "Numero da linha em que a parada sera inserida: ";
    unsigned numero_da_linha;
    cin >> numero_da_linha;
    NoEncadeavel *linha = linhas_de_onibus.BuscaLinhaPeloNumero(numero_da_linha);
    if (linha == nullptr)
    {
        cout << "Indique uma linha cadastrada." << endl;
        return;
    }
    if (linha->paradas->EstaVazia())
    {
        cout << "A lista de paradas esta vazia. Adicionando primeira parada." << endl;
        NoDuplamenteEncadeavel *nova_parada = CriarNovaParada();
        linha->paradas->AdicionaPrimeiraParada(nova_parada);
    }
    else
    {
        linha->paradas->ImprimeParadasNumeradas();
        cout << "Apos qual parada voce deseja adicionar a nova parada? ";
        unsigned indice_anterior;
        cin >> indice_anterior;
        if (indice_anterior > linha->paradas->RecuperaTamanho() || indice_anterior < 1)
        {
            cout << "Indice invalido. Escolha uma parada entre " << linha->paradas->RecuperaTamanho() << " parada(s) existente(s)." << endl;
            return;
        }
        NoDuplamenteEncadeavel *nova_parada = CriarNovaParada();
        linha->paradas->AdicionaParadaAposIndice(indice_anterior, nova_parada);
    }
}

NoDuplamenteEncadeavel *CriarNovaParada()
{
    string nome_da_parada;
    string horario_de_chegada;
    string horario_de_partida;
    cout << "Nome da nova parada: ";
    getline(cin >> ws, nome_da_parada);
    cout << "Horario de chegada: ";
    getline(cin >> ws, horario_de_chegada);
    cout << "Horario de partida: ";
    getline(cin >> ws, horario_de_partida);
    return new NoDuplamenteEncadeavel(nome_da_parada, horario_de_chegada, horario_de_partida);
}

void RemoverLinha()
{
    if (linhas_de_onibus.EstaVazia())
    {
        cout << "A lista esta vazia. Nao ha nos para remover." << endl;
        return;
    }
    unsigned numero_da_linha;
    cout << "Numero da linha para ser removida: ";
    cin >> numero_da_linha;
    linhas_de_onibus.RemoveLinhaPeloNumero(numero_da_linha);
}

void RemoverParada()
{
    cout << "De qual linha voce quer remover uma parada?" << endl;
    cout << "Numero da linha: ";
    unsigned numero_da_linha;
    cin >> numero_da_linha;
    NoEncadeavel *linha = linhas_de_onibus.BuscaLinhaPeloNumero(numero_da_linha);
    if (linha == nullptr)
    {
        cout << "Indique uma linha cadastrada." << endl;
        return;
    }
    if (linha->paradas->EstaVazia())
    {
        cout << "A lista de paradas da linha " << linha->numero_da_linha
             << " - " << linha->nome_da_companhia
             << " esta vazia. Nao ha paradas para remover." << endl;
        return;
    }
    linha->paradas->ImprimeParadasNumeradas();
    cout << "Qual parada voce quer remover?" << endl;
    cout << "Indice da parada: ";
    unsigned indice_da_parada;
    cin >> indice_da_parada;
    if (indice_da_parada > linha->paradas->RecuperaTamanho() || indice_da_parada < 1)
    {
        cout << "Indice invalido. Escolha uma parada entre " << linha->paradas->RecuperaTamanho() << " parada(s) existente(s)." << endl;
        return;
    }
    linha->paradas->RemoveParadaPeloIndice(indice_da_parada);
}
