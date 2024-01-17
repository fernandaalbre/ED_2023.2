#include <iostream>
#include <iomanip>

using namespace std;

double numeroFatorial(int n){
    double fatorial = 1;

    if(n <= 1)
        return 1;
    for(int i = 2; i <= n; i++)
        fatorial *= i;
    
    return fatorial;
}

double numeroEuler(int n){
    double e = 1;

    for(int i = 1; i <= n; i++)
        e += 1/numeroFatorial(i);
    
    return e;
}

int main(){

    double e = 0.0;
    int n = 0;

    cin >> n;

    e = numeroEuler(n);

    std::cout << std::fixed;
    cout << std::setprecision(6) << e << endl;
}