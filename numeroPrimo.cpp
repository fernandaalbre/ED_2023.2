#include <iostream>
#include <iomanip>

using namespace std;

int numeroPrimo(int n){
    int primo = 0;

    for(int i = 2; i <= (n/2); i++){
        if((n % i) == 0)
            primo ++;
    }

    if(primo == 0){
        return true;
    }else{
        return false;
    }
}

int main(){

    int a = 0, b = 0;

    cin >> a >> b;
    
    for(int i = a; i <= b; i++){
        if(numeroPrimo(i) == 1){
            cout << i << "\n";
        }
    }

}