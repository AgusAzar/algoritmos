#include <iostream>
#include <vector>
using namespace std;

void merge( vector<int> & secuencia, int left, int midle, int right ){
    //creamos dos secuencias para
    int subSecuencia1 = midle-left+1;
    int subSecuencia2 = right-midle;
    vector<int> secuenciaIzquierda(subSecuencia1);
    vector<int> secuenciaDerecha(subSecuencia2);

    for(int i = 0; i < subSecuencia1; i++){
        secuenciaIzquierda[i] = secuencia[left + i];
    }
    for(int i = 0; i < subSecuencia2; i++){
        secuenciaDerecha[i] = secuencia[midle + 1 + i];
    }

    int i=0;
    int j = 0;
    int indiceSecuenciaOriginal = left;
    while(i < subSecuencia1 && j < subSecuencia2){
        if( secuenciaIzquierda[i] <= secuenciaDerecha[j] ){
            secuencia[indiceSecuenciaOriginal] = secuenciaIzquierda[i];
            i++;
        }
        else{
            secuencia[indiceSecuenciaOriginal] = secuenciaDerecha[j];
            j++;
        }
        indiceSecuenciaOriginal++;
    }
    while( i < subSecuencia1 ){
        secuencia[indiceSecuenciaOriginal] = secuenciaIzquierda[i];
        i++;
        indiceSecuenciaOriginal++;
    }
    while( j < subSecuencia2 ){
        secuencia[indiceSecuenciaOriginal] = secuenciaDerecha[j];
        j++;
        indiceSecuenciaOriginal++;
    }
}

void mergeSort (vector<int> & secuencia, int begin, int end){
    if( begin >= end )
        return ;
    int mid = begin + (end - begin)/2;
    mergeSort(secuencia,begin, mid);
    mergeSort(secuencia,mid + 1, end);
    merge(secuencia,begin, mid, end);
}

int main(){
    vector<int> secuencia = {1,53,123,64,12,55,89,88,123,65,23,44,67,12,678,45,77,4345,785,345,75,90};
    mergeSort(secuencia, 0, secuencia.size()-1);
    for(int i = 0; i < secuencia.size(); i++){
        cout << secuencia[i] << '\n';
    }
}
