#include <iostream>
#include <vector>
#include <algorithm>
#define f first
#define s second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;


int main() {
  ll n,l,u;
  cin >> n >> l >> u;
  vector <pair<long long,long long>> w; //<peso,indice>
  for(ll  i=0; i<n; i++){
    ll  a;
    cin >> a;
    w.pb(mp(a,i));
  }
  sort(w.begin(),w.end());
  //Sumar
  ll  suma = 0;
  ll  L1,L2,numeros;
  for(ll  i=0; i<n; i++){
    suma+=w[i].f;
    if(suma>=l && suma <=u){
      cout << i+1 << endl;
      for(ll  k=0; k<=i; k++){
        cout << w[k].s << " ";
      }
      cout << endl;
      return 0;
    }
    
    else if(suma>u){
      L1 = 0;
      L2 = i-1;
      numeros = i;
      suma-=w[i].f;
      break;
    }
    
    if(i==n-1 && suma<l){
      cout << "0" << endl;
      return 0;
    }
    
  }
  
  for(ll  i=0; i<w.size()-numeros; i++){
    
    suma-=w[L1].f;
    L1++;
    L2++;
    //cout << "asfasd" << endl;
    suma+=w[L2].f;
    //cout << "shao" << endl;
    if(suma>=l && suma <=u){
      cout << L2-L1+1 << endl;
      for(ll  k=L1; k<=L2; k++){
        cout << w[k].s << " ";
      }
      cout << endl;
      return 0;
    }
    
  }
  
  
  cout << "0" << endl;
  
  return 0;
}
