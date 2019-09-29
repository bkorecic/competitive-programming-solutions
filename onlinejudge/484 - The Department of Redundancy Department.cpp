#include <iostream>
#include <vector>
#include <map>
using namespace std;
//484 - The Department of Redundancy Department
int main() {
    map <int,int> cantidades;
    vector <int> numeros;
    int N;
    while(cin>>N){
        cantidades[N]++;
        if(cantidades[N]==1){
            numeros.push_back(N);
        }
    }
    for(int i=0; i<numeros.size(); i++){
        cout << numeros.at(i) << " " << cantidades[numeros.at(i)] << endl;
    }
    return 0;
}