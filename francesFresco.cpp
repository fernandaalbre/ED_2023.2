#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main (){

    string str;
    string resultado;
    getline(cin, str); //lê a entrada

    str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
    cout << str << " ";

    for(int i = 0; i < str.size(); i++){
        
    }
    
  

   /*
   for(int i = 0; i < str.size(); i++){
        if(str[i] == '\n'){

        }

    }
   */ 

    /*for(int i = 0; i < entrada.size(); i++){
        if(entrada[i] == entrada[i+1]){
            cout << "1" ;
            resultado = resultado + entrada[i+1];
        }else
            resultado = resultado + entrada[i];
    }
    cout << resultado << endl;
    
    //return 0;*/
}