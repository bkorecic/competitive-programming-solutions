#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

multiset <int> lo, hi;
ll lo_sum=0, hi_sum=0;

void balance(){
  if(lo.size() < hi.size()){
    while(lo.size() < hi.size()-1){
      lo.insert(*hi.begin());
      lo_sum += *hi.begin();
      hi_sum -= *hi.begin();
      hi.erase(hi.begin());
    }
  }
  else{
    while(lo.size() > hi.size()){
      hi.insert(*(--lo.end()));
      hi_sum += *(--lo.end());
      lo_sum -= *(--lo.end());
      lo.erase(--lo.end());
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k; cin >> n >> k;
  vector <int> nums(n);
  for(int i=0; i<n; i++) cin >> nums[i];
  for(int i=0; i<k-1; i++){
    lo.insert(nums[i]);
    lo_sum += nums[i];
  }
  balance();
  for(int i=0; i+k-1<n; i++){
    // add nums[i+k-1]
    if((lo.empty() and hi.empty())
        or nums[i+k-1] < *hi.begin()){
      lo.insert(nums[i+k-1]);
      lo_sum += nums[i+k-1];
    }
    else{
      hi.insert(nums[i+k-1]);
      hi_sum += nums[i+k-1];
    }
    balance();
    // get median
    ll med=0;
    if(k%2 == 0){
      med = *(--lo.end());
    }
    else{
      med = *hi.begin();
    }
    cout << (med*lo.size()-lo_sum + hi_sum - med*hi.size()) << ' ';
    // remove nums[i]
    if(nums[i] < *hi.begin()){
      lo_sum -= nums[i];
      lo.erase(lo.find(nums[i]));
    }
    else{
      hi_sum -= nums[i];
      hi.erase(hi.find(nums[i]));
    }
    balance();
  } cout << '\n';
  return 0;
}
