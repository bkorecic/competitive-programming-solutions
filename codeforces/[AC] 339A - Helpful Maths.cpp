#include <bits/stdc++.h>

using namespace std;

int main(){
	
	string s1;
	vector <char> n;
	cin >> s1;
	for(int i=0; i<s1.length(); i++){
		if(i%2!=0)continue;
		n.push_back(s1[i]);
	}
	sort(n.begin(),n.end());
	for(int i=0; i<n.size(); i++){
		cout << n[i];
		if(i!=n.size()-1)cout<<"+";
	}
    return 0;
}