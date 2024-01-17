#ifndef NO_ENCADEAVEL_H
#define NO_ENCADEAVEL_H

#include "lista_duplamente_encadeada_circular.h"

#include <iostream>
#include <string>

using namespace std;

/*
    Cada elemento desta lista possui dados sobre numero da linha e a companhia e um
    ponterio para uma lista com todas as paradas.
*/

struct NoEncadeavel {
    unsigned numero_da_linha {0};
    string nome_da_companhia;
    NoEncadeavel *proximo_no;
    
    ListaDuplamenteEncadeadaCircular *paradas = new ListaDuplamenteEncadeadaCircular();

    NoEncadeavel(unsigned numero_da_linha, string nome_da_companhia, NoEncadeavel *proximo_no = nullptr) {
        this->numero_da_linha = numero_da_linha;
        this->nome_da_companhia = nome_da_companhia;
        this->proximo_no = proximo_no;
    }

    ~NoEncadeavel() {
        cout << "Excluindo paradas da linha " << numero_da_linha << " - " << nome_da_companhia << endl;
        delete paradas;
        cout << "Excluindo a linha " << numero_da_linha << " - " << nome_da_companhia << endl;
    }
};

#endif
