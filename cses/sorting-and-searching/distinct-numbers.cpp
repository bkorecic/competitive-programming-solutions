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
  set <int> nums;
  for(int i=0; i<n; i++){
    int tmp; cin >> tmp;
    nums.insert(tmp);
  }
  cout << nums.size() << '\n';
  return 0;
}
