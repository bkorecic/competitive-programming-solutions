#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

multiset <int> lo, hi;

void balance(){
  if(lo.size() < hi.size()){
    while(lo.size() < hi.size()-1){
      lo.insert(*hi.begin());
      hi.erase(hi.begin());
    }
  }
  else{
    while(lo.size() > hi.size()){
      hi.insert(*(--lo.end()));
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
  }
  balance();
  for(int i=0; i+k-1<n; i++){
    // add nums[i+k-1]
    if((lo.empty() and hi.empty())
        or nums[i+k-1] < *hi.begin())
      lo.insert(nums[i+k-1]);
    else
      hi.insert(nums[i+k-1]);
    balance();
    // print median
    if(k%2 == 0){
      cout << *(--lo.end()) << ' ';
    }
    else{
      cout << *hi.begin() << ' ';
    }
    // remove nums[i]
    if(nums[i] < *hi.begin())
      lo.erase(lo.find(nums[i]));
    else
      hi.erase(hi.find(nums[i]));
    balance();
  } cout << '\n';
  return 0;
}
