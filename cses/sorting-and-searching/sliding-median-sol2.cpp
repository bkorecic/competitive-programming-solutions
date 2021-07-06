#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k; cin >> n >> k;
  ordered_multiset o_set;
  vector <int> nums(n);
  for(int i=0; i<n; i++) cin >> nums[i];
  for(int i=0; i<k-1; i++){
    o_set.insert(nums[i]);
  }
  for(int i=0; i+k-1<n; i++){
    o_set.insert(nums[i+k-1]);
    cout << *o_set.find_by_order((k-1)/2) << ' ';
    o_set.erase(o_set.upper_bound(nums[i]));
  } cout << '\n';
  return 0;
}
