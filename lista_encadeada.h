#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include "no_encadeavel.h"

#include <iostream>
#include <string>

using namespace std;

/*
    Uma lista simplesmente encadeada de todas as linhas de onibus, organizada
    por numero da linha de onibus.
*/

class ListaEncadeada {
private:
    NoEncadeavel *primeiro_no_ = nullptr;
    NoEncadeavel *ultimo_no_ = nullptr;
    unsigned tamanho_ = {0};

public:
    ListaEncadeada() = default;

    void AdicionaNovaLinhaOrdenadamente(unsigned numero, string companhia) {
        if (this->EstaVazia()) {
            cout << "Inserindo " << numero << " numa lista vazia." << endl;
            NoEncadeavel *nova_linha = new NoEncadeavel(numero, companhia);
            this->primeiro_no_ = nova_linha;
            this->ultimo_no_ = nova_linha;
            this->tamanho_++;
            return;
        }

        if (numero < this->primeiro_no_->numero_da_linha) {
            cout << "Inserindo " << numero << " no inicio da lista." << endl;
            NoEncadeavel *nova_linha = new NoEncadeavel(numero, companhia, this->primeiro_no_);
            this->primeiro_no_ = nova_linha;
            this->tamanho_++;
            return;
        }

        if (numero > this->ultimo_no_->numero_da_linha) {
            cout << "Inserindo " << numero << " no final da lista." << endl;
            NoEncadeavel *nova_linha = new NoEncadeavel(numero, companhia);
            this->ultimo_no_->proximo_no = nova_linha;
            this->ultimo_no_ = nova_linha;
            this->tamanho_++;
            return;
        }

        NoEncadeavel *no_iterador = this->primeiro_no_;
        while (numero > no_iterador->proximo_no->numero_da_linha) {
            cout << numero << " eh maior que " << no_iterador->proximo_no->numero_da_linha << endl;
            no_iterador = no_iterador->proximo_no;
        }

        cout << numero << " eh menor ou igual a " << no_iterador->proximo_no->numero_da_linha << endl;
        cout << "Inserindo " << numero << " entre " << no_iterador->numero_da_linha << " e " << no_iterador->proximo_no->numero_da_linha << endl;

        if (no_iterador->numero_da_linha == numero) {
            cout << "Numero da linha invalido: os numeros das linhas de onibus devem ser unicos em todo o país." << endl;
            return;
        }

        NoEncadeavel *nova_linha = new NoEncadeavel(numero, companhia, no_iterador->proximo_no);
        no_iterador->proximo_no = nova_linha;
        this->tamanho_++;
    }

    NoEncadeavel *BuscaLinhaPeloNumero(unsigned numero) {
        NoEncadeavel *no_interador = this->primeiro_no_;
        while (no_interador != nullptr && numero > no_interador->numero_da_linha) {
            no_interador = no_interador->proximo_no;
        }

        if (no_interador == nullptr || no_interador->numero_da_linha != numero) {
            cout << "Linha número " << numero << " não cadastrada." << endl;
            return nullptr;
        }

        return no_interador;
    }

    void ImprimeDadosFormatados() const {
        NoEncadeavel *no_iterador = this->primeiro_no_;
        while (no_iterador != nullptr) {
            std::cout << "-----\n";
            std::cout << "Linha: " << no_iterador->numero_da_linha << "\n";
            std::cout << "Companhia: " << no_iterador->nome_da_companhia << "\n";
            std::cout << '\n';
            no_iterador = no_iterador->proximo_no;
        }
    }

    void RemoveLinhaPeloNumero(unsigned numero_da_linha_para_remover) {
        if (this->EstaVazia()) {
            cout << "A lista está vazia. Não há nós para remover." << endl;
            return;
        }

        if (this->primeiro_no_->numero_da_linha == numero_da_linha_para_remover) {
            NoEncadeavel *no_para_remover = this->primeiro_no_;
            this->primeiro_no_ = primeiro_no_->proximo_no;
            delete no_para_remover;
            this->tamanho_--;

            if (this->EstaVazia()){
                this->ultimo_no_ = nullptr;
            }
            return;
        }

        NoEncadeavel *no_iterador = this->primeiro_no_;
        while (no_iterador->proximo_no != nullptr && 
        no_iterador->proximo_no->numero_da_linha != numero_da_linha_para_remover) {
            no_iterador = no_iterador->proximo_no;
        }

        if (no_iterador->proximo_no == nullptr) {
            cout << "A linha " << numero_da_linha_para_remover 
            << " não existe. Nenhuma linha foi removida." << endl;
            return;
        }

        if (this->ultimo_no_->numero_da_linha == numero_da_linha_para_remover) {
            this->ultimo_no_ = no_iterador;
        }

        NoEncadeavel *linha_a_ser_removida = no_iterador->proximo_no;
        no_iterador->proximo_no = linha_a_ser_removida->proximo_no;
        delete linha_a_ser_removida;
        this->tamanho_--;
    }

    void EsvaziarLista() {
        while (tamanho_ > 0) {
            NoEncadeavel *auxiliar = primeiro_no_;
            primeiro_no_ = primeiro_no_->proximo_no;
            delete auxiliar;
            tamanho_--;
        }
    }

    bool EstaVazia() const {
        return tamanho_ == 0;
    }

    ~ListaEncadeada() {
        EsvaziarLista();
    }
};

#endif
