#include <iostream>
#include <string>
using namespace std;

int main() {
    //12554 - A Special Happy Birthday Song!!!
    int K;
    int repeticiones;
    cin >> K;
    string cancion[16] = {"Happy","birthday","to","you","Happy","birthday","to","you","Happy","birthday","to","Rujia","Happy","birthday","to","you",};
    string nombres[K];
    int inombres = 0;
    repeticiones = (K-1)/16 + 1;
    for(int i=0; i<K; i++){
        cin >> nombres[i];
    }
    for(int rep=0; rep<repeticiones; rep++){
        for(int i=0; i<16; i++){
            cout << nombres[inombres] << ": " << cancion[i] << endl;
            inombres++;
            if(inombres>K-1){
                inombres=0;
            }
        }
        
    }
    return 0;
}