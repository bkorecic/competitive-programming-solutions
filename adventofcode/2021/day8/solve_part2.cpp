#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...) 1313
#endif

typedef long long ll;

bool is_contained(string a, string b){
  bool ans = true;
  for(char c : a){
    if(b.find(c) == string::npos) ans = false;
  }
  return ans;
}

void rem(vector <string> &p, string s){
  p.erase(remove(p.begin(), p.end(), s), p.end());
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  string tmp;
  int ans=0;
  while(cin >> tmp){
    vector <string> patterns = {tmp};
    vector <string> decode;
    for(int i=0; i<9; i++){
      cin >> tmp;
      patterns.push_back(tmp);
    }
    cin >> tmp; // "|"
    for(int i=0; i<4; i++){
      cin >> tmp;
      decode.push_back(tmp);
    }
    for(string &s : patterns) sort(s.begin(), s.end());
    for(string &s : decode) sort(s.begin(), s.end());
    vector <string> nums(10);
    /* strategy:
     * - find 1, 4, 7, 8 by number of segments
     * - 0, 6 and 9 have 6 segments, look at those:
     *    - 9 has 4 contained
     *    - between 0 and 6, 0 has 1 contained
     *    - 6 is the remainder after getting 0 and 9
     * - 2, 3 and 5 remain
     *    - 3 has 1 contained
     *    - between 2 and 5, 5 is contained in 6 
     *    - 2 is the remaining one
     */
    for(string s : patterns){ // find 1, 4, 7, 8
      if(s.size() == 2) nums[1] = s;
      if(s.size() == 4) nums[4] = s;
      if(s.size() == 3) nums[7] = s;
      if(s.size() == 7) nums[8] = s;
    }
    rem(patterns, nums[1]);
    rem(patterns, nums[4]);
    rem(patterns, nums[7]);
    rem(patterns, nums[8]);
    vector <string> size6;
    for(string s : patterns){
      if(s.size() == 6) size6.push_back(s);
    }
    for(string s : size6){
      if(is_contained(nums[4], s)) nums[9] = s;
    }
    rem(size6, nums[9]);
    for(string s : size6){
      if(is_contained(nums[1], s)) nums[0] = s;
    }
    rem(size6, nums[0]);
    nums[6] = size6[0];
    rem(patterns, nums[0]);
    rem(patterns, nums[6]);
    rem(patterns, nums[9]);
    for(string s : patterns){
      if(is_contained(nums[1], s)) nums[3] = s;
    }
    rem(patterns, nums[3]);
    for(string s : patterns){
      if(is_contained(s, nums[6])) nums[5]=s;
    }
    rem(patterns, nums[5]);
    nums[2] = patterns[0];
    // start decoding
    string num="";
    for(string s : decode){
      for(int i=0; i<=9; i++){
        if(s == nums[i]){
          num += ('0'+i);
        }
      }
    }
    //dbg("decoded: ", num);
    ans += stoi(num);
  }
  cout << ans << '\n';
  return 0;
}
