#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// complejidad peor caso O(√n)
bool buscar (vector<int> secuencia, int n){
    int salto = (int)sqrt(secuencia.size());
    int i = 0;
    while (i < secuencia.size() && secuencia[i] < n) {
        cout << secuencia[i] << "\n";
        i += salto;
    }
    i -=salto;
    while( i < secuencia.size() && secuencia[i] != n ){
        cout << secuencia[i] << "\n";
        i++;
    }
    return secuencia[i] == n;
}

int main(){
    int n;
    bool res;
    vector<int> secuencia = {3,5,12,13,15,17,18,20,34,36,39,40,44,48,49,50,53,55,58,60,63,66,69,71,73,74};
    cout << "ingrese un numero a buscar \n";
    cin >> n;
    res = buscar(secuencia,n);
    cout<< res;
}
