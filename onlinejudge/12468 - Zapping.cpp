#include <iostream>
#include <cmath>
using namespace std;
int main() {
    //12468 - Zapping
    int a,b;
    cin >> a >> b;
    while(a != -1){ 
        //hacia arriba: (100-a) + b
        //hacia abajo: (a) + (100-b)
        //directo: abs(a-b)
        cout << min(min((100-b+a),(100-a+b)),abs(a-b)) << endl;
        cin >> a >> b;
    }
    return 0;
}