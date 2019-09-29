#include <iostream>
#include <cmath>
using namespace std;

int main() {
    //Combinación de Cerradura
    int fin=0;
    int inicial;
    int a;
    int b;
    int c;
    int d1;
    int d2;
    int d3;
    while(fin<1) {
        cin >> inicial;
        cin >> a;
        cin >> b;
        cin >> c;
        inicial = 9*inicial;
        a = 9*a;
        b = 9*b;
        c = 9*c;
        if (inicial == 0 && a == 0 && b == 0 && c == 0) {
            fin=10;
        }
        else {
            if (inicial >= a) {
                d1 = (inicial-a);   
            }
            else {
                d1 = 360-(a-inicial);
            }
            
            if (a >= b) {
                d2 = 360-(a-b);   
            }
            else {
                d2 = (b-a);
            }
            
            if (b >= c) {
                d3 = (b-c);   
            }
            else {
                d3 = 360-(c-b);
            }
            int suma = 1080 + d1 + d2 + d3;
            cout << suma << endl;

        }
    }
    return 0;
}