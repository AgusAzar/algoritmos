#include <iostream>
#include <vector>
using namespace std;

// complejidad peor caso O(n²)
// complejidad promedio O(n*log(n))
void ordenar (vector<int> & secuencia , int low , int high){
    int j = low;
    int i = low -1;
    int pivote = high;
    if( low < high ){
        while( j < pivote ){
            if( secuencia[j] <= secuencia[pivote] ){
                i ++;
                int aux = secuencia[j];
                secuencia[j]=secuencia[i];
                secuencia[i] = aux;
            }
            j++;
        }
        int aux = secuencia[pivote];
        secuencia[pivote]=secuencia[i+1];
        secuencia[i+1] = aux;

        ordenar(secuencia, low, i);
        ordenar(secuencia, i+1, high);
    }
}

int main(){
    vector<int> secuencia = {1,53,123,64,12,55,89,88,123,65,23,44,67,12,678,45,77,4345,785,345,75,90};
    ordenar(secuencia, 0, secuencia.size() -1);
    for(int i = 0; i < secuencia.size(); i++){
        cout << secuencia[i] << '\n';
    }
}
