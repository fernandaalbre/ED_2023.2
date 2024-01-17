#ifndef LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H
#define LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H

#include "no_duplamente_encadeavel.h"

#include <iostream>
#include <string>

using namespace std;

/*
    Uma lista duplamente encadeada circular... onde cada elemento dessa
    lista possui dados referentes a uma parada do ônibus.
*/

class ListaDuplamenteEncadeadaCircular {
private:
    NoDuplamenteEncadeavel *no_sentinela_ = nullptr;
    unsigned tamanho_ = {0};

public:
    ListaDuplamenteEncadeadaCircular() = default;

    /*
    Incluir uma parada numa linha... o usuário... digita o número da
    parada após a qual ele quer inserir uma parada...
    */

    void AdicionaParadaAposIndice(unsigned indice_anterior, NoDuplamenteEncadeavel *nova_parada) {
        if (indice_anterior > this->tamanho_) {
            cout << "Indice de parada fora do intervalo de paradas." << endl;
            return;
        }

        NoDuplamenteEncadeavel *no_iterador = this->no_sentinela_;
        unsigned counter = 1;
        while (counter < indice_anterior) {
            no_iterador = no_iterador->proximo_no;
            counter++;
        }

        nova_parada->no_anterior = no_iterador;
        nova_parada->proximo_no = no_iterador->proximo_no;
        no_iterador->proximo_no->no_anterior = nova_parada;
        no_iterador->proximo_no = nova_parada;
        this->tamanho_++;
    }

    void AdicionaPrimeiraParada(NoDuplamenteEncadeavel *primeira_parada) {
        primeira_parada->no_anterior = primeira_parada;
        primeira_parada->proximo_no = primeira_parada;
        this->no_sentinela_ = primeira_parada;
        this->tamanho_++;
    }

    void AlteraParadaPeloIndice(unsigned indice, string nome, string chegada, string partida) {
        if (indice < 1 || indice > this->tamanho_) {
            cout << "Indice de parada fora do intervalo de paradas." << endl;
            return;
        }

        NoDuplamenteEncadeavel *no_iterador = this->no_sentinela_;
        unsigned counter = 1;
        while (counter < indice) {
            no_iterador = no_iterador->proximo_no;
            counter++;
        }

        no_iterador->nome_da_parada = nome;
        no_iterador->horario_de_chegada = chegada;
        no_iterador->horario_de_partida = partida;
        cout << "Parada alterada para " << nome << " ("
            << chegada << " - " << partida << ")." << endl;
    }

    void ImprimeParadasNumeradas() const {
        NoDuplamenteEncadeavel *no_iterador = this->no_sentinela_;
        unsigned contador = 1;

        while (contador <= this->tamanho_) {
            cout << "-----\n";
            cout << "Parada " << contador++ << endl;
            cout << "Nome da parada: " << no_iterador->nome_da_parada << "\n";
            cout << "Horario de chegada: " << no_iterador->horario_de_chegada << "\n";
            cout << "Horario de partida: " << no_iterador->horario_de_partida << "\n";
            cout << '\n';
            no_iterador = no_iterador->proximo_no;
        }
    }

    bool EstaVazia() const {
        return tamanho_ == 0;
    }

    void EsvaziarLista() {
        while (tamanho_ > 0) {
            NoDuplamenteEncadeavel *auxiliar = no_sentinela_;
            no_sentinela_ = no_sentinela_->proximo_no;
            delete auxiliar;
            tamanho_--;
        }
    }

    unsigned RecuperaTamanho() const {
        return this->tamanho_;
    }

    void RemoveParadaPeloIndice(unsigned indice) {
        if (indice < 1 || indice > this->tamanho_) {
            cout << "Indice de parada fora do intervalo de paradas." << endl;
            return;
        }

        NoDuplamenteEncadeavel *no_iterador = this->no_sentinela_;
        unsigned counter = 1;
        while (counter < indice) {
            no_iterador = no_iterador->proximo_no;
            counter++;
        }

        no_iterador->proximo_no->no_anterior = no_iterador->no_anterior;
        no_iterador->no_anterior->proximo_no = no_iterador->proximo_no;
        this->no_sentinela_ = no_iterador->proximo_no;

        if (this->tamanho_ == 1) {
            this->no_sentinela_ = nullptr;
        }

        delete no_iterador;
        this->tamanho_--;
    }

    ~ListaDuplamenteEncadeadaCircular() {
        EsvaziarLista();
    }
};

#endif
