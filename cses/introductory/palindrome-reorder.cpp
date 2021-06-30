#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

const int ALPH = 'Z'-'A'+1;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  int n = s.size();
  vector <int> char_cnt(ALPH, 0);
  for(int i=0; i<n; i++){
    char_cnt[s[i]-'A']++;
  }
  int odd = 0;
  for(auto x : char_cnt){
    odd += x%2;
  }
  if(odd>n%2){
    cout << "NO SOLUTION\n";
    return 0;
  }
  char middle;
  for(int i=0, j=n-1; i<j; i++, j--){
    for(int k=0; k<ALPH; k++){
      while(i<j and char_cnt[k] >= 2){
        s[i] = s[j] = 'A'+k;
        char_cnt[k] -= 2;
        i++;
        j--;
      }
      if(char_cnt[k] == 1) middle = 'A'+k;
    }
  }
  if(n>1 and n%2 == 1){
    s[n/2] = middle;
  }
  cout << s << '\n';
  return 0;
}
