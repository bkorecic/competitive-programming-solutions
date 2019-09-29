#include <bits/stdc++.h>
using namespace std;

int main(){
	int s,v1,v2,t1,t2,tiempo1=0,tiempo2=0;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	tiempo1+=2*t1 + s*v1;
	tiempo2+=2*t2 + s*v2;
	if(tiempo1<tiempo2)cout<<"First\n";
	else if(tiempo1>tiempo2)cout<<"Second\n";
	else cout << "Friendship\n";
	return 0;
}