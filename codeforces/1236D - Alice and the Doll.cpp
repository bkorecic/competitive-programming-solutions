#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m, k; cin >> n >> m >> k;
    if(k == 0){
        cout << "Yes\n";
        return 0;
    }
    ll total = 1; 
    set <pii> x_sort;
    set <pii> y_sort;
    for(int i=0; i<k; i++){
        int x, y; cin >> x >> y;
        x_sort.insert(mp(x,y));
        y_sort.insert(mp(y,x));
    }
    bool stop = false;
    int x = 1, y = 1;
    int dir = 0;
    int next_x, next_y;
    int up_lim = 1; // x = 1 up empieza con 1 más!!
    int left_lim = 0; // y = 1
    int right_lim = m+1; // y = n
    int down_lim = n+1; // x = n
    //cout << "\tTEST: " << it->f << ' ' << it->s << '\n';
    while(!stop){
        if(dir == 0){
            auto it = x_sort.upper_bound(mp(x,y));
            int new_y;
            if(it != x_sort.end() && it->f == x){
                new_y = min(it->s-1, right_lim-1); 
            }
            else{
                new_y = right_lim-1;
            }
            total += new_y - y;
            y = new_y;
            right_lim = y;
        }
        else if(dir == 1){
            auto it = y_sort.upper_bound(mp(y,x));
            int new_x;
            if(it != y_sort.end() && it->f == y){
                new_x = min(it->s-1, down_lim-1);
            }
            else{
                new_x = down_lim-1;
            }
            total += new_x - x;
            x = new_x;
            down_lim = x;
            
        }
        else if(dir == 2){
            auto it = x_sort.upper_bound(mp(x,y));
            it--;
            int new_y;
            if(it != x_sort.end() && it->f == x && *it < mp(x,y)){
                new_y = max(it->s+1, left_lim+1);
            }
            else{
                new_y = left_lim+1;
            }
            total += y - new_y;
            y = new_y;
            left_lim = y;
        }
        else{
            auto it = y_sort.upper_bound(mp(y,x));
            it--;
            int new_x;
            if(it != y_sort.end() && it->f == y && *it < mp(y,x)){
                new_x = max(it->s+1, up_lim+1);
            }
            else{
                new_x = up_lim+1;
            }
            total += x - new_x;
            x = new_x;
            up_lim = x;
        }
        //cout << "\tx, y = " << x << ", " << y << ' ' << total << '\n';
        dir = (dir+1)%4;
        if(x_sort.find(mp(x+dir_x[dir], y+dir_y[dir])) != x_sort.end()) stop = true;
        else if(dir == 0){
            //cout << y << ' ' << right_lim << '\n';
            if(y+1 >= right_lim) stop = true;
        }
        else if(dir == 1){
            //cout << x << ' ' << down_lim << '\n';
            if(x+1 >= down_lim) stop = true;
        }
        else if(dir == 2){
            //cout << y << ' ' << left_lim << '\n';
            if(y-1 <= left_lim) stop = true;
        }
        else{
            //cout << x << ' ' << up_lim << '\n';
            if(x-1 <= up_lim) stop = true;
        } /*
        cout << (x+dir_x[dir] <= up_lim) << ' ' << up_lim << '\n';
        cout << (x+dir_x[dir] >= down_lim) << ' ' << down_lim << '\n';
        cout << (y+dir_y[dir] >= right_lim) << ' ' << right_lim << '\n';
        cout << (y+dir_y[dir] <= left_lim) << ' ' << left_lim << '\n'; 
        if(x + dir_x[dir] <= up_lim || x + dir_x[dir] >= down_lim
            || y + dir_y[dir] >= right_lim || y + dir_y[dir] <= left_lim
            || x_sort.find(mp(x+dir_x[dir], y+dir_y[dir])) != x_sort.end()) stop = true;
            */
        //cout << '\n';
    }
    if(total == n*m - k) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

