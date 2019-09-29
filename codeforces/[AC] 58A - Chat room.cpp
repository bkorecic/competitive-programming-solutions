#include <bits/stdc++.h>
using namespace std;

int main() {
  string a; cin >> a;
  
  vector <int> pos(5,1e6+1);
  
  int len = a.length();
  
  for(int i=0; i<len; i++){
    if(a[i] == 'h'){
      pos[0]=i; 
      break;
    }
  }
  
  for(int i=0; i<len; i++){
    if(a[i] == 'e' && i>pos[0]){
      pos[1]=i; 
      break;
    }
  }
  
  for(int i=0; i<len; i++){
    if(a[i] == 'l' && i>pos[1]){
      pos[2]=i; 
      break;
    }
  }
  
  for(int i=0; i<len; i++){
    if(a[i] == 'l' && i>pos[2]){
      pos[3]=i; 
      break;
    }
  }
  
  for(int i=0; i<len; i++){
    if(a[i] == 'o' && i>pos[3]){
      pos[4]=i; 
      break;
    }
  }
  
  if(pos[4]!=1e6+1)cout << "YES\n";
  else cout << "NO\n";
  
  return 0;
}