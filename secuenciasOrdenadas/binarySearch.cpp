#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

//complejidad O(log2(n))
bool buscar (vector<int> secuencia, int n, int inicio, int final){
    int high = final;
    int low = inicio;
    while( low+1 < high && secuencia[low] != n ) {
        int mid = (low+high) / 2;
        if( secuencia[mid] <= n ) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return secuencia[low] == n;
}

int main(){
    int n;
    bool res;
    vector<int> secuencia = {3,5,12,13,15,17,18,20,34,36,39,40,44,48,49,50,53,55,58,60,63,66,69,71,73,74};
    cout << "ingrese un numero a buscar \n";
    cin >> n;
    res = buscar(secuencia,n,0,secuencia.size()-1);
    cout<< res;
}
