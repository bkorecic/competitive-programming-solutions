#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

double PI = acos(-1);

double to_radians(double angle){
    return angle*(PI/180.0);
}

void rotate(pair<double,double> &vec, double angle){
    double x = vec.f, y = vec.s;
    double xnew =  x*cos(angle) + y*sin(angle);
    double ynew = -x*sin(angle) + y*cos(angle);
    vec.f = xnew;
    vec.s = ynew;
}

void solve(){
    int n; cin >> n;
    double alfa = 360.0/(2.0*n);
    double beta = (180.0-alfa)/2.0;
    double gamma = 180.0-2.0*beta;
    //cout << alfa << ' ' << beta << ' ' << gamma << endl;
    pair<double,double> vec = {1,0};
    double x = 0, y = 1;
    for(int i=0; i<(2*n-4)/4; i++){
        rotate(vec, to_radians(gamma));
        //cout << "angle: " << gamma << ' ' << vec.f << ' ' << vec.s << endl;
        x += vec.f; y += vec.s;
    }
    cout << fixed << setprecision(9) << 1 + 2*x << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
