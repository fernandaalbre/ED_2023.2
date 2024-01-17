#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main() {

    /*
            Primeiras Atividades 
                    Pintando a casa
    float a = 0, b = 0, c= 0, p = 0;
    float area = 0;

    cout << "Digite os tres lados da casa: " << "\n";

    cin >> a >> b >> c;
    cout << "\n";

    p = (a+b+c)/2;
    cout.precision(2);
    area = sqrt((p*(p-a)*(p-b)*(p-c)));
    //float area2 = round(area * 100) / 100;
    cout << std::fixed << "sua area e de: " << area << "\n";*/


                //Quem chega mais perto
    
    int valorPro = 0, chutePri = 0, chuteSeg = 0, aux = 0, aux1 = 0;

    cin >> valorPro;
    cin >> chutePri;
    cin >> chuteSeg;

    aux = valorPro - chutePri;
    aux1 = valorPro - chuteSeg;

    if(abs(aux) < abs(aux1)){
        cout << "primeiro";
    } else if(abs(aux) > abs(aux1)){
        cout << "segundo";
    } else {
        cout << "empate";
    }

    

}