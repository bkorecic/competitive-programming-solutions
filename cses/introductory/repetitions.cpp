#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  int n = s.size();
  int ans = 1;
  int block = 1;
  for(int i=1; i<n; i++){
    if(s[i] == s[i-1]){
      block++;
      ans = max(ans, block);
    }
    else{
      block = 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
