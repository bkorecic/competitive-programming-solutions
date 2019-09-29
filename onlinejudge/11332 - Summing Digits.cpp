#include <iostream>
#include <cmath>
using namespace std;

int main() {
    //11332 - Summing Digits
    int K;
    int digitos;
    cin >> K;
    while(K!=0){
        digitos=log10(K)+1;
        while(digitos>1){
            int cifra[digitos];
            for(int i=0; i<digitos; i++){
                cifra[digitos-i-1]=K%10;
                K = K/10;
            }
            for(int i=0; i<digitos; i++){
                K+= cifra[i];
            }
            digitos=log10(K)+1;
        }
    cout << K << endl;
    cin >> K;     
    }
    return 0;
}