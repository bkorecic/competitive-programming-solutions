#include <iostream>
#include <string>
using namespace std;

int main() {
    //Searching for Nessy
    int K;
    cin >> K;
    int filas;
    int columnas;
    for(int rep=0; rep<K; rep++) { 
        cin >> filas;
        cin >> columnas;
        cout << ((filas)/3) * ((columnas)/3) << endl;
    }
    return 0;
}