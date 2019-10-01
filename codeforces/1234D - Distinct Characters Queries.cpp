#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
const int inf = -1;
 
struct SegmentTree
{
	vector<int> ST;
	int N;
 
	SegmentTree(vector<int> &A)
	{
		N = A.size();
 
		// Recordar 4*N
		ST.resize(4*N);
 
		build(1,0,N-1,A);
	}
 
	void build(int n, int l, int r, vector<int> &A)
	{	
		// Chequeo si es hoja
		if(l == r)
		{
			ST[n] = A[r];
			return;
		}
 
		// Construyo los hijos
		build(2*n,l,(l+r)/2,A);
		build(2*n+1,(l+r)/2+1,r,A);
 
		// Computo los valores
		ST[n] = max(ST[2*n],ST[2*n+1]);
	}
 
	int query(int i, int j)
	{
		return query(1,0,N-1,i,j);
	}
 
	// Computa la query(i,j) para el nodo n
	int query(int n, int l, int r, int i, int j)
	{
		// Caso 1: No chocan
		if(r < i || j < l) return inf;
 
		// Caso 2: Contenido totalmente
		if(i <= l && r <= j) return ST[n];
 
		// Caso 3: Ninguno de los anteriores
		// Le paso la query a los hijos
 
		return max(query(2*n,l,(l+r)/2,i,j),
					query(2*n+1,(l+r)/2+1,r,i,j));
	}
 
	// Setea A[i] = v
	void update(int i, int v)
	{
		return update(1,0,N-1,i,v);
	}
 
	void update(int n, int l, int r, int i, int v)
	{
		// Si no contiene a i, no hacer nada
		if(i < l || r < i) return;
 
		// Chequear si es hoja
		if(l == r)
		{
			ST[n] = v;
			return;
		}
 
		// Actualizar a los hijos
		update(2*n,l,(l+r)/2,i,v);
		update(2*n+1,(l+r)/2+1,r,i,v);
 
		// Recomputo los valores
		ST[n] = max(ST[2*n],ST[2*n+1]);
	}
};
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int q; cin >> q;
    int alphabet_size = 'z'-'a'+1;
    vector <vector<int>> convert_string(alphabet_size, vector<int>(s.size(), 0));
    for(int i=0; i<s.size(); i++){
        int get_index = s[i] - 'a';
        convert_string[get_index][i] = 1;
    }
    vector <int> placeholder(1,0);
    vector <SegmentTree> vst;
    for(int i=0; i<alphabet_size; i++){
        SegmentTree ST(convert_string[i]);
        vst.push_back(ST);
    }
    while(q--){
        int query_type;
        cin >> query_type;
        if(query_type == 1){
            int index; char new_char;
            cin >> index >> new_char;
            index--;
            char old_char = s[index];
            vst[old_char - 'a'].update(index, 0);
            vst[new_char - 'a'].update(index, 1);
            s[index] = new_char;
        }
        else{
            int L, R; cin >> L >> R;
            L--; R--;
            int ans = 0;
            for(int i=0; i < alphabet_size; i++){
                ans += vst[i].query(L, R);
            }
            cout << ans << '\n';
        }
        /*
        for(int i=0; i<3; i++){
            for(int j=0; i<s.size(); j++){
                cout << vst[i].query(j,j);
            } cout << endl;
        }
        */
    }
    return 0;
}
