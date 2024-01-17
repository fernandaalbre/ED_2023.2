#ifndef NO_DUPLAMENTE_ENCADEAVEL_H
#define NO_DUPLAMENTE_ENCADEAVEL_H

#include <iostream>
#include <string>

using namespace std;

/*
    Neste elemento estao informacoes sobre o nome da parada, o horario de
    chegada do onibus na rodoviaria e o horario de saida do onibus da rodoviaria.
*/

struct NoDuplamenteEncadeavel {
    string nome_da_parada;
    string horario_de_chegada;
    string horario_de_partida;
    NoDuplamenteEncadeavel *no_anterior;
    NoDuplamenteEncadeavel *proximo_no;

    NoDuplamenteEncadeavel(string nome_da_parada, string chegada, string partida) {
        this->nome_da_parada = nome_da_parada;
        this->horario_de_chegada = chegada;
        this->horario_de_partida = partida;
    }

    ~NoDuplamenteEncadeavel() {
            cout << "Excluindo a parada " << nome_da_parada
                << " (" << horario_de_chegada << " - "
                << horario_de_partida << ")." << endl;
    }
};

#endif
