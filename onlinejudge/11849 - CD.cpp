#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    //11849 - CD
    int A,B;
    cin >> A >> B;
    while(A!=0 && B!=0){
        int coincidencias = 0;
        int jack[A];
        int jill[B];
        //Escribir arreglos
        for(int i=0; i<A; i++){
            int aux;
            cin >> aux;
            jack[i] = aux;
        }
        for(int i=0; i<B; i++){
            int aux;
            cin >> aux;
            jill[i] = aux;
        }
        //Busqueda Binaria
        for(int i=0; i<A; i++){
            bool resultado = binary_search(jill,jill+B,jack[i]);
                if(resultado == true){
                    coincidencias++;
                }
            
        }
        cout << coincidencias << endl;
        cin >> A >> B;
    }
    return 0;
}