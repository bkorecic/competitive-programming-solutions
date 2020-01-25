#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
 
ll dist(pll a, pll b){
    return abs(a.f-b.f) + abs(a.s-b.s);   
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll xo, yo, ax, ay, bx, by;
    cin >> xo >> yo >> ax >> ay >> bx >> by;
    ll xs, ys, t;
    cin >> xs >> ys >> t;
    pll initial = make_pair(xs, ys);
    vector <pll> points;
    points.push_back(make_pair(xo,yo));
    int i = 1;
    ll distance_first = dist(initial, points[0]);
    while(true){
        pll new_point = make_pair(ax*points[i-1].f + bx, ay*points[i-1].s + by);
        if(dist(initial, new_point) > t && !(dist(initial, new_point) < distance_first)) break;
        points.push_back(new_point);
        i++;
    }
    int total_points = i;
    /*
    cout << "total_points = " << total_points << '\n';
    for(int i=0; i<total_points; i++){
        cout << i << '\t' << points[i].f << ' ' << points[i].s << '\n';
    }
    */
    int cur_node;
    int tmp_ans;
    ll cur_time;
    int ans = 0;
    for(int i=0; i<total_points; i++){
        cur_time = dist(initial, points[i]);
        cur_node = i;
        tmp_ans = 0;
        if(cur_time <= t) tmp_ans = 1;
        while(cur_node > 0 && cur_time + dist(points[cur_node], points[cur_node-1]) <= t){
            //cout << '\t' << cur_node << ' ' << cur_time << '\n';
            tmp_ans++;
            cur_time += dist(points[cur_node], points[cur_node-1]);
            cur_node--;
        }
        ans = max(ans, tmp_ans);
        //cout << i << ' ' << ans << '\n';
    }
    cur_time = dist(initial, points[0]);
    cur_node = 0;
    if(cur_time <= t) tmp_ans = 1;
    while(cur_node < total_points-1 && cur_time + dist(points[cur_node], points[cur_node+1]) <= t){
        //cout << cur_node << ' ' << cur_time << '\n';
        tmp_ans++;
        cur_time += dist(points[cur_node], points[cur_node+1]);
        cur_node++;
    }
    ans = max(ans, tmp_ans);
    cout << ans << '\n';
    return 0;
}
