#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)

#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
  int s,n;
  cin >> s >> n;
  vii d;
  F0R(i, n){
    int a,b;
    cin >> a >> b;
    d.pb(mp(a,b));
  }
  bool can = true;
  sort(d.begin(),d.end());
  F0R(i, n){
    if(s>d[i].f){
      s+=d[i].s;
    }
    else{
      can = false;
      break;
    }
  }
  if(can){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
  }
  return 0;
}
