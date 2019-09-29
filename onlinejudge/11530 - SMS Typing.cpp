#include <iostream>
#include <string>
using namespace std;
int transformar(char a){
	if(a=='a' || a=='d' || a=='g' || a=='j' || a=='m' || a=='p' || a=='t' || a=='w' || a==' ') {
		return 1;
	}
	else if(a=='b' || a=='e' || a=='h' || a=='k' || a=='n' || a=='q' || a=='u' || a=='x'){
		return 2;
	}
	else if(a=='c' || a=='f' || a=='i' || a=='l' || a=='o' || a=='r' || a=='v' || a=='y'){
		return 3;
	}
	else if(a=='s' || a=='z'){
		return 4;
	}
}

int main(){
	int rep;
	string linea;
	cin >> rep;
	getline(cin,linea);
	for(int i=0; i<rep; i++){
		getline(cin,linea);
		int largo = linea.length();
		int suma = 0;
		for(int k=0; k<largo; k++){
			suma = suma+(transformar(linea[k]));
		}
		cout << "Case #" << i+1 << ": " << suma << endl;
	}
return 0;
}

