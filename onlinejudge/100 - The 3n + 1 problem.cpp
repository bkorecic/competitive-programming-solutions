#include <iostream>
#include <cmath>

using namespace std;
int calcular(int a){    
    int repeticiones = 0;
    while(a!=1){
        if(a%2==0){
            a = a/2;
        }
        else{
            a = (3*a) + 1;
        }
        repeticiones++;
    }
    return repeticiones; 
}

int main() {
    //100 - The 3n + 1 problem
    int a,b;
    while(cin>>a){
        cin >> b;
        int numeros = abs(a-b) + 1;
        int valores[numeros];
        for(int i=0; i<numeros; i++){
            valores[i] = (calcular(min(a,b)+i));
        }
        int menor = -1;
        for(int i=0; i<numeros; i++){
            if(valores[i]>menor){
                menor = valores[i];
            }
        }
        cout << a << " " << b << " " << menor+1 << endl;
    }
    return 0;
}