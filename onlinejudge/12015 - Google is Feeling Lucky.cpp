#include <iostream>
using namespace std;

int main() {
    //12015 - Google is Feeling Lucky
    int n;
    string nombres[10];
    int relevancia[10];
    cin >> n;
    for (int a=0; a<n; a++){
        int mayor = 0;
        int mayorIndice = 0;
        //Escribir array
        for (int i=0; i<10; i++){
            cin >> nombres[i];
            cin >> relevancia[i];
        }
        //Buscar primera mayor relevancia
        for (int i=0; i<10; i++){
            if(relevancia[i]>mayor){
                mayor = relevancia[i];
            }
        }
        //Buscar e imprimir el mayor y sus empates
        cout << "Case #" << a+1 << ":" << endl;
        for (int i=0; i<10; i++){
            if(relevancia[i]==mayor){
                cout << nombres[i] << endl;
                
            }
            
        }
    }
    return 0;
}