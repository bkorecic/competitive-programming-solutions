#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#define pb push_back
using namespace std;

int main() {
  // MAXSC - Maximum Score
  long long T, N;
  cin >> T;
  for(long long rep=0; rep<T; rep++){
    //Setup
    long long suma = 0;
    long long last = 10000000000;
    bool flag = true;
    cin >> N;
    vector <vector<long long>> series;
    series.assign(N,vector<long long>());
    for(long long k=0; k<N; k++){
        for(long long m=0; m<N; m++){
          long long h;
          cin >> h;
          series[k].pb(h);
        }
      }
    //
    for(long long i=0; i<N; i++){
      //Definir max element
      long long aux;
      
      if(*min_element(series[N-1-i].begin(),series[N-1-i].end()) >= last){
        cout << "-1" << endl;
        flag = false;
        break;
      }
      
      long long mejor = -10;
      for(long long a=0; a<N; a++){
        if(series[N-1-i][a] < last && series[N-1-i][a] > mejor){
          mejor = series[N-1-i][a];
          continue;
        }
      }
      last = mejor;
      suma += last;
    }
    if(flag == true){
      cout << suma << endl;
    }
  }
  return 0;
}