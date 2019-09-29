#include <iostream>
#include <vector>
#include <string>
using namespace std;

void aBraille(string a){
    
    vector <string> primeraLinea;
    vector <string> segundaLinea;
    vector <string> terceraLinea;
    
    for(int i=0; i<a.length(); i++){
        char aux = a[i];
        if(aux == '0'){
            primeraLinea.push_back(".*");
            segundaLinea.push_back("**");
            terceraLinea.push_back("..");
            
        }
        else if(aux == '1'){
            primeraLinea.push_back("*.");
            segundaLinea.push_back("..");
            terceraLinea.push_back("..");
            
        }
        
        else if(aux == '2'){
            primeraLinea.push_back("*.");
            segundaLinea.push_back("*.");
            terceraLinea.push_back("..");
            
        
        }
        else if(aux == '3'){
            primeraLinea.push_back("**");
            segundaLinea.push_back("..");
            terceraLinea.push_back("..");
            
        
        }
        else if(aux == '4'){
            primeraLinea.push_back("**");
            segundaLinea.push_back(".*");
            terceraLinea.push_back("..");
            
        
        }
        else if(aux == '5'){
            primeraLinea.push_back("*.");
            segundaLinea.push_back(".*");
            terceraLinea.push_back("..");
            
        
        }
        else if(aux == '6'){
            primeraLinea.push_back("**");
            segundaLinea.push_back("*.");
            terceraLinea.push_back("..");
            
        
        }
        else if(aux == '7'){
            primeraLinea.push_back("**");
            segundaLinea.push_back("**");
            terceraLinea.push_back("..");
            
        
        }
        else if(aux == '8'){
            primeraLinea.push_back("*.");
            segundaLinea.push_back("**");
            terceraLinea.push_back("..");
            
        
        }
        else if(aux == '9'){
            primeraLinea.push_back(".*");
            segundaLinea.push_back("*.");
            terceraLinea.push_back("..");
            
        
        }
    } 
    
    
        for(int k=0; k<a.length(); k++){
            
            if(k == a.length()-1){
                cout << primeraLinea[k] << endl;
            }
            else{
                cout << primeraLinea[k] << " ";
            }
            
        }
        
        for(int k=0; k<a.length(); k++){
            
            if(k == a.length()-1){
                cout << segundaLinea[k] << endl;
            }
            else{
                cout << segundaLinea[k] << " ";
            }
            
        }
        
        
        for(int k=0; k<a.length(); k++){
            
            if(k == a.length()-1){
                cout << terceraLinea[k] << endl;
            }
            else{
                cout << terceraLinea[k] << " ";
            }
            
        }
}
    
void aDigitos(vector<string> a, vector<string> b, vector<string> c){
    vector <int> digitos;
    for(int i=0; i<a.size(); i++){
        if(a[i] == "*."){
            if(b[i] == ".."){
                digitos.push_back(1);
            }
            else if(b[i] == "*."){
                digitos.push_back(2);
            }
            else if(b[i] == "**"){
                digitos.push_back(8);
            }
            else{
                digitos.push_back(5);
            }
        }
        
        else if(a[i] == "**"){
            if(b[i] == "*."){
                digitos.push_back(6);
            }
            else if(b[i] == "**"){
                digitos.push_back(7);
            }
            else if(b[i] == ".*"){
                digitos.push_back(4);
            }
            else{
                digitos.push_back(3);
            }
        }
        
        else if(a[i] == ".*"){
            if(b[i] == "**"){
                digitos.push_back(0);
            }
            else{
                digitos.push_back(9);   
            }
        }
        
    }
    
    for(int i=0; i<digitos.size(); i++){
        if(i==digitos.size()-1){
            cout << digitos[i] << endl;
        }
        else{
            cout << digitos[i];
        }
    }
}

int main() {
    // 12364 - In Braille
    int N;
    cin >> N;
    getchar();
    while(N!=0){
        char M;
        cin >> M;
        if(M == 'S'){
            string s1;
            cin >> s1;
            aBraille(s1);
        }
        
        else if(M == 'B'){
            vector<string> primera;
            vector<string> segunda;
            vector<string> tercera;
            
            for(int i=0; i<N; i++){
                string aux;
                cin >> aux;
                primera.push_back(aux);
            }
            for(int i=0; i<N; i++){
                string aux;
                cin >> aux;
                segunda.push_back(aux);
            }
            
            for(int i=0; i<N; i++){
                string aux;
                cin >> aux;
                tercera.push_back(aux);
            }
            
            aDigitos(primera,segunda,tercera);
        }
        cin >> N;
        getchar();
    }
    return 0;
}