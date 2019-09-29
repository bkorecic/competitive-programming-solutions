#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    //10474 - Where is the Marble?
    int N, Q;
    int caso = 1;
    cin >> N >> Q;
    while(N!=0){
        vector <int> numeros;
        for(int i=0; i<N; i++){
            int numero;
            cin >> numero;
            numeros.push_back(numero);
        }
        sort(numeros.begin(),numeros.end());
        cout << "CASE# " << caso << ":" << endl;
        for(int i=0; i<Q; i++){
            int query;
            cin >> query;
            //Buscar:
            for(int a=0; a<numeros.size(); a++){
                if(numeros.at(a) == query){
                    cout << query << " found at " << a+1 << endl;
                    break;
                }
                if(numeros.at(a)!= query && a==numeros.size()-1){
                    cout << query << " not found" << endl;
                }
            }
        }
        caso++;
        cin >> N >> Q;
    }
    return 0;
}