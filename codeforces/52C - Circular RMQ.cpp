#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e13;
struct SegmentTree
{
	vector<ll> ST, L;
	int N;

	SegmentTree(vector<ll> &A)
	{
		N = A.size();

		// Recordar 4*N
		ST.resize(4*N);
		L.resize(4*N,0);

		build(1,0,N-1,A);
	}

	void build(int n, int l, int r, vector<ll> &A)
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
		ST[n] = min(ST[2*n],ST[2*n+1]);
	}

	ll query(int i, int j)
	{
		return query(1,0,N-1,i,j);
	}

	// Computa la query(i,j) para el nodo n
	ll query(int n, int l, int r, int i, int j)
	{
		// Si hay que actualizar el nodo
		if(L[n] != 0)
		{
			// Actualizo el valor
			ST[n] += L[n];

			// Si no es hoja, marco a los hijos
			if(l != r)
			{
				L[2*n] += L[n];
				L[2*n+1] += L[n];
			}

			// Desmarco al nodo
			L[n] = 0;
		}

		// Caso 1: No chocan
		if(r < i || j < l) return inf;

		// Caso 2: Contenido totalmente
		if(i <= l && r <= j) return ST[n];

		// Caso 3: Ninguno de los anteriores
		// Le paso la query a los hijos

		return min(query(2*n,l,(l+r)/2,i,j),
					query(2*n+1,(l+r)/2+1,r,i,j));
	}

	// A[i,j] += v
	void update(int i, int j, ll v)
	{
		return update(1,0,N-1,i,j,v);
	}

	void update(int n, int l, int r, int i, int j, ll v)
	{
		// Si hay que actualizar el nodo
		if(L[n] != 0)
		{
			// Actualizo el valor
			ST[n] += L[n];

			// Si no es hoja, marco a los hijos
			if(l != r)
			{
				L[2*n] += L[n];
				L[2*n+1] += L[n];
			}

			// Desmarco al nodo
			L[n] = 0;
		}

		// Caso 1: No chocan
		if(j < l || r < i) return;

		// Caso 2: Contenido totalmente
		if(i <= l && r <= j)
		{
			// Actualizo el valor
			ST[n] += v;

			// Si no es hoja, marco a los hijos
			if(l != r)
			{
				L[2*n] += v;
				L[2*n+1] += v;
			}

			// Desmarco al nodo
			L[n] = 0;

			return;
		}

		// Caso 3: Ninguno de los anteriores
		// Actualizar a los hijos
		update(2*n,l,(l+r)/2,i,j,v);
		update(2*n+1,(l+r)/2+1,r,i,j,v);

		// Recomputo los valores
		ST[n] = min(ST[2*n],ST[2*n+1]);
	}
	void print(){
		for(int x : ST){
			cout << x << ' ';
		} cout << '\n';
	}
};


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector <ll> nums(n);
	for(int i=0; i<n; i++) cin >> nums[i];
	int m; cin >> m;
	SegmentTree ST(nums);
	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b;
		ll v;
		//ST.print();
		if(cin.peek() == '\n'){
			//cout << "CASO DOS NUMEROS\n";
			if(a > b){
				ll first = ST.query(a, n-1);
				ll second = ST.query(0, b);
				cout << min(first, second) << '\n';
			}
			else{
				cout << ST.query(a, b) << '\n';
			}
		}
		else{
			//cout << "CASO TRES NUMEROS\n";
			cin >> v;
			if(a > b){
				ST.update(a, n-1, v);
				ST.update(0, b, v);
			}
			else{
				ST.update(a, b, v);
			}
		}
	}
	return 0;
}