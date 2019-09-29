#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int menor(int a, int b, int c, int d, int e, int f) {
    int a1 = min(a,b);
    int a2 = min(c,d);
    int a3 = min(e,f);
    int resultado = min(min(a1,a2),a3);
    return resultado;
}

int main() {
    //102 - Ecological Bin Packing
    int B, G, C;
    int bin1[3], bin2[3], bin3[3];
    int caso1,caso2,caso3,caso4,caso5,caso6;
    while(cin >> B){
        cin >> G >> C;
        bin1[0] = B;
        bin1[1] = G;
        bin1[2] = C;
        cin >> B >> G >> C;
        bin2[0] = B;
        bin2[1] = G;
        bin2[2] = C;
        cin >> B >> G >> C;
        bin3[0] = B;
        bin3[1] = G;
        bin3[2] = C;
        // Casos:
        // 1-BGC, 2-BCG
        // 3-GBC, 4-GCB
        // 5-CBG, 6-CGB
        caso1 = bin2[0] + bin3[0] + bin1[1] + bin3[1] + bin1[2] + bin2[2];
        caso2 = bin2[0] + bin3[0] + bin1[2] + bin3[2] + bin1[1] + bin2[1];
        caso3 = bin2[1] + bin3[1] + bin1[0] + bin3[0] + bin1[2] + bin2[2];
        caso4 = bin2[1] + bin3[1] + bin1[2] + bin3[2] + bin1[0] + bin2[0];
        caso5 = bin2[2] + bin3[2] + bin1[0] + bin3[0] + bin1[1] + bin2[1];
        caso6 = bin2[2] + bin3[2] + bin1[1] + bin3[1] + bin1[0] + bin2[0];
        int minimo = menor(caso1,caso2,caso3,caso4,caso5,caso6);
        if(minimo == caso2){
            cout << "BCG ";
        }
        else if(minimo == caso1){
            cout << "BGC ";
        }
        else if(minimo == caso5){
            cout << "CBG ";
        }
        else if(minimo == caso6){
            cout << "CGB ";
        }
        else if(minimo == caso3){
            cout << "GBC ";
        }
        else if(minimo == caso4){
            cout << "GCB ";
        }
        cout << minimo << endl;
    }
    return 0;
}