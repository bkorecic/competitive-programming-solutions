#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

void move(int n, int from, int to, int aux){
  if(n == 1){
    cout << from << ' ' << to << '\n';
    return;
  }
  move(n-1, from, aux, to);
  cout << from << ' ' << to << '\n';
  move(n-1, aux, to, from);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  cout << (1<<n)-1 << '\n';
  move(n, 1, 3, 2);
  return 0;
}
