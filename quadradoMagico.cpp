#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int magico[3][3];

    int somaLinha = 0, somaColuna = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> magico[i][j];
        }
    }

    /*for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << magico[i][j] << " ";
        }
        cout << endl;
    }*/

    for(int i = 0; i < 3; i++){
        int soma = 0;
        for(int j = 0; j < 3; j++){
            soma += magico[i][j];
        }
        somaLinha = soma;
    }

    for(int j = 0; j < 3; j++){
        int soma1 = 0;
        for(int i = 0; i < 3; i++){
            soma1 += magico[i][j];
        }
        somaColuna = soma1;
    }

    if(somaLinha == somaColuna){
        cout << "sim";
    }else{
        cout << "nao";
    }

}