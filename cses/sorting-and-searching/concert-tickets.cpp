#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  multiset <int> s;
  for(int i=0; i<n; i++){
    int tmp; cin >> tmp;
    s.insert(tmp);
  }
  for(int i=0; i<m; i++){
    int q; cin >> q;
    auto p = s.upper_bound(q);
    if(p == s.begin()){
      cout << "-1" << '\n';
    }
    else{
      p--;
      cout << *p << '\n';
      s.erase(p);
    }
  }
  return 0;
}
