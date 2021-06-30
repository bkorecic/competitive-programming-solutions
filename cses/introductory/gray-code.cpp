#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector <string> ans = {"0", "1"};
  for(int b=0; b<n-1; b++){
    int tmp = ans.size();
    for(int i=tmp-1; i>=0; i--){
      ans.push_back(ans[i]);
      ans[i] += '0';
      ans[ans.size()-1] += '1';
    }
  }
  for(string s : ans){
    cout << s << '\n';
  }
  return 0;
}
