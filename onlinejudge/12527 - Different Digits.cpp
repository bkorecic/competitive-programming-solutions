#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool revisar(int a) {
    vector <int> digitos;
    int aux = a;
    
    int size = log10(aux) + 1;
    for(int i=0; i<size; i++){
        int size2 = log10(aux) + 1;
        int digito = aux/(pow(10,size2-1));
        digitos.push_back(digito);
        aux = aux - digito*pow(10,size2-1);
    }
    
    //for(int i=0; i<size; i++){
    //    cout << digitos[i] << " " << endl;
    //}
    
    for(int i=0; i<size; i++){
        for(int k=0; k<size; k++){
            if(digitos[i] == digitos[k] && i!=k){
                return false;
            }
        }
    }
    return true;
    
}

int main() {
    //12527 - Different Digits
    int N,M;
    while(cin >> N >> M){
        int low = min(N,M);
        int up = max(N,M);
        
        int rep = up - low + 1;
        int conteo = 0;
        for(int i=0; i<rep; i++){
            if(revisar(low+i) == true){
                conteo++;
            }
        }
        cout << conteo << endl;
    }
    return 0;
}