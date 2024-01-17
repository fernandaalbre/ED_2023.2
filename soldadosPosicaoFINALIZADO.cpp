#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    int tam = 3;
    int matriz[tam][tam] = {{2,4,6}, {3,8,9}, {1,0,5}};
    int atual = 0, aux = 0;

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }

    for(int j = 0; j < tam; j++){
        for(int i = 0; i < tam; i++){
            atual = matriz[i][j];
            if(atual > aux){
                aux = atual;
            }
            else {
                cout << aux << " ";
                aux = 0;
            }
        }
    }

    





    return 0;
}