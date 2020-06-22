#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector <int> nums(n);
    vector <bool> in_nums(1e6,false);
    for(int i=0; i<n; i++){
        cin >> nums[i];
        in_nums[nums[i]] = true;
        if(nums[i] > i+1){
            cout << -1 << '\n';
            return 0;
        }
    }

    priority_queue <int, vector<int>, greater<int>> pq;

    for(int i=0; i<=nums[i-1]+n; i++){
        if(!in_nums[i]) pq.push(i);
    }
    for(int i=0; i<n; i++){
        int put = pq.top();
        pq.pop();
        cout << put << " \n"[i==n-1];
        if(i<n-1 && nums[i+1] != nums[i]) pq.push(nums[i]);
    }

    return 0;
}
