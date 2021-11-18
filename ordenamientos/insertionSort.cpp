#include <iostream>
#include <vector>
using namespace std;

// complejidad peor caso O(n²)
// complejidad promedio O(n²)
void ordenar (vector<int> & secuencia){
    int i = 1;
    int j;
    while( i < secuencia.size() ){
        int key = secuencia[i];
        j= i-1;
        while( j >= 0 && secuencia[j] > key ){
            secuencia[j + 1] = secuencia[j];
            j = j - 1;
        }
        secuencia[j + 1] = key;
        i++;
    }
}

int main(){
    vector<int> secuencia = {1,53,123,64,12,55,89,88,123,65,23,44,67,12,678,45,77,4345,785,345,75,90};
    ordenar(secuencia);
    for(int i = 0; i < secuencia.size(); i++){
        cout << secuencia[i] << '\n';
    }
}
