#include iostream
#include map
#include string
using namespace std;

int main() {
    10282 - Babelfish
    map string,string diccionario;
    string linea, p1, p2;
    int espacio;
    while(getline(cin,linea)){
        if(linea.empty()){
            break;
        }
        espacio = linea.find( );
        p1 = linea.substr(0,espacio);
        p2 = linea.substr(espacio+1);
        diccionario[p2] = p1;
    }
    string traducir;
    while(cin  traducir){
        if(diccionario[traducir].empty()){
            cout  eh  endl;
        }
        else{
            cout  diccionario[traducir]  endl;
        }
    }
    return 0;
}