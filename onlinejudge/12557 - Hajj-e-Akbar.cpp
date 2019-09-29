#include <iostream>
using namespace std;

int main() {
	//Hajj-e-Akbar
    string nombre;
    int caso = 1;
    cin >> nombre;
    while(nombre != "*") {
        if(nombre == "Hajj") { 
            cout << "Case " << caso << ": " << "Hajj-e-Akbar" << endl;
        }
        else{
            cout << "Case " << caso << ": " << "Hajj-e-Asghar" << endl;
        }
        caso++;
        cin >> nombre;
    }
    return 0;
}