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
  vector <int> nums(n);
  map <int, int> pos;
  for(int i=0; i<n; i++){
    cin >> nums[i];
    pos[nums[i]] = i;
  }
  int ans = 1;
  for(auto a=pos.begin(), b=++pos.begin(); b != pos.end(); a++, b++){
    auto p1 = *a;
    auto p2 = *b;
    if(p2.s < p1.s) ans++;
  }
  for(int q=0; q<m; q++){
    int i, j; cin >> i >> j;
    i--, j--;
    int x = nums[i], y = nums[j];
    if(x>1 and i<pos[x-1] and j>=pos[x-1]) ans--;
    if(x>1 and i>pos[x-1] and j<=pos[x-1]) ans++;
    if(x<n and i<pos[x+1] and j>=pos[x+1]) ans++;
    if(x<n and i>pos[x+1] and j<=pos[x+1]) ans--;
    if(x!=y-1 and y>1 and j<pos[y-1] and i>=pos[y-1]) ans--;
    if(x!=y-1 and y>1 and j>pos[y-1] and i<=pos[y-1]) ans++;
    if(x!=y+1 and y<n and j<pos[y+1] and i>=pos[y+1]) ans++;
    if(x!=y+1 and y<n and j>pos[y+1] and i<=pos[y+1]) ans--;
    pos[nums[i]] = j;
    pos[nums[j]] = i;
    swap(nums[i], nums[j]);
    cout << ans << '\n';
  }
  return 0;
}
