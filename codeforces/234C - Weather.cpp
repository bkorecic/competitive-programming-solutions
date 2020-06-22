#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ifstream inFile;
    inFile.open("input.txt");
    
    int n; inFile >> n;
    vector <ll> nums(n);
    for(int i=0; i<n; i++){
        inFile >> nums[i];
    }
    inFile.close();
 
    vector <int> positive_left(n,0); // inclusive
    vector <int> negative_right(n,0); // inclusive
    if(nums[0] >= 0) positive_left[0] = 1;
    for(int i=1; i<n; i++){
        positive_left[i] = positive_left[i-1] + (nums[i]>=0);
    }
    if(nums[n-1] <= 0) negative_right[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        negative_right[i] = negative_right[i+1] + (nums[i]<=0);
    }
    int ans = n;
    for(int i=1; i<n; i++){
        int cans = positive_left[i-1] + negative_right[i];
        ans = min(ans, cans);
    }
 
    ofstream outFile("output.txt");
 
    outFile << ans << '\n';
    return 0;
}
