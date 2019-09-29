#include <iostream>
#include <string>
using namespace std;

int main() {
    //TEX Quotes
    string linea;
    int alternar = 1;
    while (getline(cin,linea)) {
        for (int i=0; i<linea.length(); i++) {
            if(linea[i] == '"' && alternar == 1) {
                cout << "``";
                alternar = 0;
            }
            else if(linea[i] == '"' && alternar == 0) {
                cout << "''";
                alternar = 1;
            }
            else{
                cout << linea[i];
            }
        }
        cout << endl;
        
    }
    return 0;
}