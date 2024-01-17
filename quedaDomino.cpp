#include <iostream>
#include <iomanip>

using namespace std;

bool verifica (int v[], int n) {
   int k = 1;
   if (n > 1){
        for (int i = 1; i < n; i++){
            if (v[i-1] <= v[i]){
                k++;
            }
            else{
                return true;
            }
        }
        if (k == n){
            return false;
        }
   }
}

int main(){
    int n = 0;
    cin >> n;

     int queda[n];

    for(int i=0; i<n; i++){
        cin >> queda[i];
    }

    /*for(int i = 0; i < n; i++){
        cout << queda[i] << " ";
    }

    cout << endl;*/

   if (verifica(queda,n) == false){
        cout << "ok";
    } else{
        cout << "precisa de ajuste";
    }

}