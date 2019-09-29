#include <iostream>
#include <queue>
using namespace std;

int main() {
    //10954 - Add All
    priority_queue <int> cola;
    int N;
    cin >> N;
    while(N!=0){
        //Escribir
        for(int i=0; i<N; i++){
            int aux;
            cin>>aux;
            aux = aux*(-1);
            cola.push(aux);
        }
        int suma = 0;
        while(cola.size()>1){
            int a,b;
            a = cola.top();
            cola.pop();
            b = cola.top();
            cola.pop();
            cola.push(a+b);
            suma = suma - (a+b);
        }
        for(int i=0; i<cola.size(); i++){
            cola.pop();
        }
        cout << suma << endl;
        cin>>N;
    }
    return 0;
}