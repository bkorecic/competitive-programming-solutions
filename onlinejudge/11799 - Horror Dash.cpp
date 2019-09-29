#include <iostream>
using namespace std;

int main() {
    //11799 - Horror Dash
    int K;
    int N;
    int mayor;
    cin >> K;
    for(int rep=0; rep<K; rep++){
        mayor = 0;
        cin >> N;
        int velocidades[N];
        for(int i=0; i<N; i++){
            cin >> velocidades[i];
        }
        //Buscar mayor
        for(int i=0; i<N; i++){
            if(velocidades[i]>mayor){
                mayor = velocidades[i];
            }
        }
        cout << "Case " << rep+1 << ": " << mayor << endl;
    }
    return 0;
}