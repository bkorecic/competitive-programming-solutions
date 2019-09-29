#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coincidencias (int x,int y,int z){
    if(x!=y && x!=z && y!=z){
        return 0;
    }
    else if(x==y && x==z && y==z){
        return 3;
    }
    else{
        return 2;
    }
}

int desapareado (int x,int y,int z){
    vector <int> numeros;
    numeros.push_back(x);
    numeros.push_back(y);
    numeros.push_back(z);
    
    sort(numeros.begin(),numeros.end());
    
    if(numeros[0] == numeros[1]){
        return numeros[2];
    }
    else{
        return numeros[0];
    }
}


int apareado (int x,int y,int z){
    vector <int> numeros;
    numeros.push_back(x);
    numeros.push_back(y);
    numeros.push_back(z);
    
    sort(numeros.begin(),numeros.end());
    
    if(numeros[0] == numeros[1]){
        return numeros[0];
    }
    else{
        return numeros[2];
    }
}


int main() {
    //12366 - King's Poker
    int a, b, c;
    cin >> a >> b >> c;
    while(a!=0){
        
        if(coincidencias(a,b,c)==0){
            cout << "1 1 2" << endl;
        }
        
        else if(coincidencias(a,b,c)==2){
            if (desapareado(a,b,c) == 12 && apareado(a,b,c) == 13){
                cout << "1 1 1" << endl;
            }
            else if (desapareado(a,b,c)+1 == apareado(a,b,c)){
                cout << min(apareado(a,b,c),desapareado(a,b,c)+2) << " " << apareado(a,b,c) << " " << max(apareado(a,b,c),desapareado(a,b,c)+2) << endl;
            }
            else if (desapareado(a,b,c) == 13){
                cout << "1 " << apareado(a,b,c)+1 << " " << apareado(a,b,c)+1 << endl;
            }
            else{
                cout << min(apareado(a,b,c),desapareado(a,b,c)+1) << " " << apareado(a,b,c) << " " << max(apareado(a,b,c),desapareado(a,b,c)+1) << endl;
            }
            
            
            
        }
        
        else if(coincidencias(a,b,c)==3){
            if(a==13){
                cout << "*" << endl;
            }
            else{
                cout << a+1 << " " << a+1 << " " << a+1 << endl;
            }
        }
        
        cin >> a >> b >> c;
    }
    return 0;
}