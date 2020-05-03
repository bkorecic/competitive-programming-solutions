#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector <ll> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        vector <int> peak(n,0);
        for(int i=1; i<n-1; i++){
            if(a[i-1] < a[i] && a[i] > a[i+1]) peak[i] = 1;
        }
        vector <int> peak_sum(n,0);
        for(int i=1; i<n; i++){
            peak_sum[i] = peak[i] + peak_sum[i-1];
        }
        int max_peaks = 0;
        int min_l = 0;
        /*
        for(int i=0; i<n; i++){
            cout << peak[i] << ' ' ;
        } cout << endl;
        for(int i=0; i<n; i++){
            cout << peak_sum[i] << ' ';
        } cout << endl;
        */
        for(int l=0; l+k-1 < n; l++){
            int restar=0;
            if(l>0) restar = peak_sum[l-1];
            int peaks = peak_sum[l+k-1] - restar;
            peaks -= peak[l];
            peaks -= peak[l+k-1];
            if(peaks > max_peaks){
                max_peaks = peaks;
                min_l = l;
            }
        }
        cout << max_peaks+1 << ' ' << min_l+1 << '\n';
    }
    
    return 0;
}