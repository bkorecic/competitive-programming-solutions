#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int convertir(char a){
	if(a == 'W'){
		return 64;
	}
	else if(a == 'H'){
		return 32;
	}
	else if(a == 'Q'){
		return 16;
	}
	else if(a == 'E'){
		return 8;
	}
	else if(a == 'S'){
		return 4;
	}
	else if(a == 'T'){
		return 2;
	}
	else if(a == 'X'){
		return 1;
	}
}


int main(){
	//12195 - Jingle Composing
	string linea;
	int total, acum, largo;
	while(true){
		getline(cin,linea);
		
		if(linea[0]=='*'){
			return 0;
		}
		
		largo = linea.length();
		acum = 0;
		total = 0;
		for(int i=0; i<linea.length(); i++){
			if(linea[i] != '/'){
				acum = acum + convertir(linea[i]);
			}
			if(linea[i] == '/'){
				if(acum==64){
					total++;
				}
				acum=0;
			}
		}
		
		cout << total << endl;
	}
return 0;
}

