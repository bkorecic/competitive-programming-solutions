#include <iostream>
using namespace std;

int main() {
    //Chess - 278
    int repeticiones;
    string pieza;
    int x;
    int y;
    int king1;
    int king2;
    cin >> repeticiones;
    for(int i = 0; i<repeticiones; i++) {
        cin >> pieza;
        cin >> x;
        cin >> y;
        
        if (pieza == "r") {
            cout << min(x,y) << endl;
        }
        
        if (pieza == "k") {
            if((x*y)%2==0) {
                cout << x*y/2 << endl;
            }
            else {
                cout << (x*y+1)/2 << endl;
            }
        }
        
        if (pieza == "Q") {
            cout << min(x,y) << endl;
        }
        
        if (pieza == "K") {
            if(x%2==0){
                king1 = x/2;
            }
            else {
                king1 = (x+1)/2;
            }
            
            if(y%2==0){
                king2 = y/2;
            }
            else {
                king2 = (y+1)/2;
            }
            
            cout << king1*king2 << endl;
        }
    }
    return 0;
}