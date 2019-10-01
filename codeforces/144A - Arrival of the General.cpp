#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main() {
  int N; cin >> N;
  vector <int> s(N);
  for(int i=0; i<N; i++){
    cin >> s[i];
  }
  pair <int,int> mini = {101,0};
  pair <int,int> maxi = {0,0};
  for(int i=0; i<N; i++){
    if(s[i] > maxi.f)maxi={s[i],i};
  }
  
  for(int i=N-1; i>=0; i--){
    if(s[i] < mini.f)mini={s[i],i};
  }
  
  if(maxi.s > mini.s)cout<<maxi.s+(N-1-mini.s)-1<<'\n';
  else cout<<maxi.s+(N-1-mini.s)<<'\n';
  
  return 0;
}
