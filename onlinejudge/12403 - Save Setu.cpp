#include <iostream>
using namespace std;

int main() {
    //Save Setu
    int K;
    int suma = 0;
    int sumando;
    string operacion;
    cin >> K;
    for(int rep=0; rep<K; rep++){
        sumando=0;
        cin >> operacion;
        if(operacion == "donate"){
            cin>>sumando;
            suma = suma + sumando;
        }
        else{
            cout << suma << endl;
        }
    }
    return 0;
}