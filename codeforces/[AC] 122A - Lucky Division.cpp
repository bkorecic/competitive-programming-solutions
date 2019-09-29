#include <bits/stdc++.h>
using namespace std;

int LuckyNumbers[12] = {4,7,47,74,444,447,474,744,777,774,747,477};

bool checkLucky(int a){
  
  int size = log10(a) + 1;
  
  for(int i=0; i<size-1; i++){
    int d = a%10;
    if(d!=4 && d!=7)return false;
    a/=10;
  }
  return true;
}

int main() {
  int N;cin>>N;
  for(int i=0; i<12; i++){
    if(N%LuckyNumbers[i]==0){
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}