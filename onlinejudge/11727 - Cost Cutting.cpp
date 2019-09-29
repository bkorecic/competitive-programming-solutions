#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    //Cost Cutting
    int K;
    int salarios[3];
    int mayor;
    int menor;
    int mayorIndice;
    int menorIndice;
    int finalIndice;
    cin >> K;
    for(int rep=0; rep<K; rep++){
        mayor = 0;
        menor = 10001;
        mayorIndice = 0;
        menorIndice = 0;
        finalIndice = 0;
        cin >> salarios[0];
        cin >> salarios[1];
        cin >> salarios[2];
        //Buscar mayor
        for(int i=0; i<3; i++){
            if(salarios[i] > mayor) {
                mayor = salarios[i];
                mayorIndice = i;
            }
        }
        //Buscar menor
        for(int i=0; i<3; i++) {
            if(salarios[i] < menor) {
                menor = salarios[i];
                menorIndice = i;
            }
        }
        salarios[menorIndice] = 0;
        salarios[mayorIndice] = 0;
        mayor = 0;
        for(int i=0; i<3; i++){
            if(salarios[i] > mayor) {
                finalIndice = i;
            }
        }
        cout << "Case " << rep+1 << ": " << salarios[finalIndice] << endl;
    }
    return 0;
}