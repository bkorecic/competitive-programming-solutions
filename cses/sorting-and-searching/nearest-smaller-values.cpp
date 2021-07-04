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
  stack <pair<int,int>> nums;
  for(int i=0; i<n; i++){
    int cur; cin >> cur;
    while(!nums.empty() and nums.top().f >= cur) nums.pop();
    if(nums.empty()){
      cout << 0 << ' ';
    }
    else{
      cout << nums.top().s+1 << ' ';
    }
    nums.push({cur, i});
  } cout << '\n';
  return 0;
}
