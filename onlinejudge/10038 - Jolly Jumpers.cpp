#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    //10038 - Jolly Jumpers
    int N;
    while(cin>>N){
        if(N == 1){
            cout << "Jolly" << endl;
            vector <int> numeros;
            for(int i=0; i<N; i++){
                int a;
                cin >> a;
                numeros.push_back(a);
            }
        }
        else{
            vector <int> numeros;
            vector <int> diferencias;
            for(int i=0; i<N; i++){
                int a;
                cin >> a;
                numeros.push_back(a);
            }
            //Calcular diferencias:
            for(int i=0; i<N-1; i++){
                diferencias.push_back(abs(numeros.at(i)-numeros.at(i+1)));
                //cout << diferencias.at(i) << endl; //Debug
            }
            sort(diferencias.begin(),diferencias.end());
            for(int i=0; i<N-1; i++){
                if(diferencias.at(i) == i+1 && diferencias.at(i) == N-1){
                    cout << "Jolly" << endl;
                }
                else if(diferencias.at(i) != i+1){
                    cout << "Not jolly" << endl;
                    break;
                }
            }
        }
    }
    return 0;
}