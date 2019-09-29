#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    //Language Detection
    int caso = 1;
    string palabra;
    cin >> palabra;
    while(palabra !="#"){
        if(palabra=="HELLO") {
            cout << "Case " << caso << ": " << "ENGLISH" << endl;
        }
        else if(palabra=="HOLA") {
            cout << "Case " << caso << ": " << "SPANISH" << endl;
        }
        else if(palabra=="HALLO") {
            cout << "Case " << caso << ": " << "GERMAN" << endl;
        }
        else if(palabra=="BONJOUR") {
            cout << "Case " << caso << ": " << "FRENCH" << endl;
        }
        else if(palabra=="CIAO") {
            cout << "Case " << caso << ": " << "ITALIAN" << endl;
        }
        else if(palabra=="ZDRAVSTVUJTE") {
            cout << "Case " << caso << ": " << "RUSSIAN" << endl;
        }
        else {
            cout << "Case " << caso << ": " << "UNKNOWN" << endl;
        }
        caso++;
        cin >> palabra;
    }
    return 0;
}