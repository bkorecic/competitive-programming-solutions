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
  sort(s.begin(), s.end());
  vector <string> ans;
  do{
    ans.push_back(s);
  } while(next_permutation(s.begin(), s.end()));
  cout << ans.size() << '\n';
  for(string t : ans) cout << t << '\n';
  return 0;
}
