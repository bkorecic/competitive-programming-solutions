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
  map <char, int> close_score = {{'(', 1}, {'[', 2}, {'<', 4}, {'{', 3}};
  vector <ll> scores;
  while(cin >> s){
    stack <char> stk;
    bool consider=true;
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
          consider=false;
          break;
        }
      }
    }
    if(!consider) continue;
    ll sc=0;
    while(!stk.empty()){
      char c = stk.top();
      stk.pop();
      sc *= 5;
      sc += close_score[c];
    }
    scores.push_back(sc);
  }
  sort(scores.begin(), scores.end());
  cout << scores[scores.size()/2] << '\n';

  return 0;
}

