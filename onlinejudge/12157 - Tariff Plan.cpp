#include <iostream>
#include <cstring>
using namespace std;
int main() {
    //12157 - Tariff Plan
    int K;
    int N;
    int s;
    int sumaMile;
    int sumaJuice;
    cin >> K;
    for(int rep=0; rep<K; rep++){
        cin >> N;
        sumaMile = 0;
        sumaJuice = 0;
        for (int i=0; i<N; i++){
            cin >> s;
            sumaMile = sumaMile + 10*((s/30)+1);
            sumaJuice = sumaJuice + 15*((s/60)+1);
        }
        if(min(sumaMile,sumaJuice) == sumaMile && sumaMile != sumaJuice) {
            cout << "Case " << rep+1 << ": " << "Mile " << sumaMile << endl;
         }
        else if(sumaMile == sumaJuice){
            cout << "Case " << rep+1 << ": " << "Mile Juice " << sumaJuice << endl;
        }
        else{
            cout << "Case " << rep+1 << ": " << "Juice " << sumaJuice << endl;
        }
    }
    return 0;
}