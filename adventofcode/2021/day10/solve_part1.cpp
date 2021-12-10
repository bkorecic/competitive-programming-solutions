#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...) 1313
#endif

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  int ans = 0;
  set <char> open = {'(', '[', '<', '{'};
  map <char, char> close_mp = {{')', '('}, {']', '['}, {'>', '<'}, {'}', '{'}};
  map <char, int> close_score = {{')', 3}, {']', 57}, {'>', 25137}, {'}', 1197}};
  while(cin >> s){
    stack <char> stk;
    for(char c : s){
      if(open.count(c)){
        stk.push(c);
      }
      else{
        char match = close_mp[c];
        if(stk.top() == match){
          stk.pop();
        }
        else{
          ans += close_score[c];
          break;
        }
      }
    }
  }
  cout << ans << '\n';

  return 0;
}

