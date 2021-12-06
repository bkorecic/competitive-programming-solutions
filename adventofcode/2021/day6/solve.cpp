#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...) 1313
#endif

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int x;
  vector <ll> freq(9, 0);
  while(cin >> x){
    freq[x]++;
    cin.ignore();
  }
  int it=256;
  while(it--){
    vector <ll> freq_new(9, 0);
    for(int i=0; i<=7; i++) freq_new[i] = freq[i+1];
    freq_new[8] += freq[0];
    freq_new[6] += freq[0];
    freq = freq_new;
  }
  ll sum=0;
  for(ll num : freq) sum += num;
  cout << sum << '\n';
  return 0;
}
