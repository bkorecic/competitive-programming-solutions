#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int x, n; cin >> x >> n;
  set <int> s = {0, x};
  multiset <int> diffs = {x};
  for(int i=0; i<n; i++){
    int p; cin >> p;
    auto it = s.lower_bound(p);
    int r = *(it--);
    int l = *it;
    int len = r-l;
    s.insert(p);
    diffs.erase(diffs.find(len));
    diffs.insert(r-p);
    diffs.insert(p-l);
    cout << *diffs.rbegin() << ' ';
  } cout << '\n';
  return 0;
}
